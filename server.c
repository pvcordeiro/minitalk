/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 11:05:22 by paude-so          #+#    #+#             */
/*   Updated: 2025/01/03 15:04:47 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>

static void	ft_putnbr(long nb)
{
	char	digit;

	if (nb >= 10)
		ft_putnbr(nb / 10);
	digit = nb % 10 + '0';
	write(1, &digit, 1);
}

static void	bit_handler(int bit, siginfo_t *info, void *unused)
{
	static char	c = 0;
	static int	i = 0;

	(void)unused;
	if (bit == SIGUSR1)
		c |= (1 << i);
	else if (bit == SIGUSR2)
		c &= ~(1 << i);
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		c = 0;
		i = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	write (1, "Server PID: ", 12);
	ft_putnbr(getpid());
	write (1, "\n", 1);
	sa.sa_sigaction = bit_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
