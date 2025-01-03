/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 11:05:22 by paude-so          #+#    #+#             */
/*   Updated: 2025/01/03 14:15:40 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
	if (i == CHAR_BIT)
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

	ft_printf("Server PID: %d\n", getpid());
	sa.sa_sigaction = bit_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
