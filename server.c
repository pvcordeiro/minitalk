/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 11:05:22 by paude-so          #+#    #+#             */
/*   Updated: 2025/01/03 12:37:20 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int bit)
{
	static int	c;
	static int	bit;

	if (bit == SIGUSR1)
		c += 1 << bit;
	bit++;
	if (bit == 8)
	{
		if (c == '\0')
		{
			ft_printf("Message received: %s\n", c);
			c = 0;
		}
		else
			ft_printf("%c", c);
		bit = 0;
	}
}

int	main(void)
{
	ft_printf("Server PID: %d\n", getpid());
	while (1)
	{
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);
		pause();
	}
	return (0);	
}
