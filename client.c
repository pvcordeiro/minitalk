/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 11:18:21 by paude-so          #+#    #+#             */
/*   Updated: 2025/01/03 15:12:39 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>

static volatile sig_atomic_t	g_sig_received = 0;

static void	sig_handler(int unused)
{
	(void)unused;
	g_sig_received = 1;
}

static int	ft_atoi(const char *str)
{
	int	result;

	result = 0;
	while (*str >= '0' && *str <= '9')
		result = result * 10 + (*(str)++ - '0');
	return (result);
}

int	send_char(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		g_sig_received = 0;
		if (c & (1 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (!g_sig_received)
			usleep(42);
		bit++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*message;

	signal(SIGUSR1, sig_handler);
	if (argc != 3)
		return (write (1, "Usage: ./client [PID] [MESSAGE]\n", 32));
	pid = ft_atoi(argv[1]);
	message = argv[2];
	while (*message)
		send_char(pid, *message++);
	send_char(pid, '\0');
	return (0);
}
