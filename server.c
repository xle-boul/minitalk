/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:53:24 by xle-boul          #+#    #+#             */
/*   Updated: 2022/02/01 14:17:41 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_binary[7];

char	ft_conversion(int *g_binary)
{
	int	c;
	int	i;
	int	n;

	n = 64;
	i = 0;
	c = 0;
	while (n > 0)
	{
		c += n * g_binary[i];
		n /= 2;
		i++;
	}
	return (c);
}

void	ft_interpret_signals(int sig)
{
	char		c;
	static int	i;

	g_binary[i] = sig;
	write(1, &g_binary[i], 1);
	i++;
	if (i % 7 == 0)
	{
		i = 0;
		c = ft_conversion(g_binary);
		write(1, &c, 1);
	}
}

void	signalhandler0(int sig)
{
	(void)sig;
	ft_interpret_signals(0);
}

void	signalhandler1(int sig)
{
	(void)sig;
	ft_interpret_signals(1);
}

int	main(void)
{
	int	pid;

	pid = getpid();
	signal(SIGUSR1, signalhandler0);
	signal(SIGUSR2, signalhandler1);
	write(1, "PID = ", 6);
	ft_putnbr(pid);
	write(1, "\n", 1);
	while (1)
	{
		sleep(1);
	}
	return (0);
}
