/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 17:16:35 by xle-boul          #+#    #+#             */
/*   Updated: 2022/02/07 10:49:48 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"
#include <stdio.h>

// use of a global array to store each signal
// recieved as a part of a bits sequence

int	g_binary[8];

char	ft_conversion(int *g_binary)
{
	int	c;
	int	i;
	int	n;

	n = 128;
	i = 0;
	c = 0;
	while (i < 8)
	{
		c += n * g_binary[i];
		n /= 2;
		i++;
	}
	return ((unsigned char)c);
}

// recieve signals and store them into the global variable
// so that each char is split into 8 bits
// once the variable is full, print its content as
// the corresponding character
// tells the program what to do once it has recieved a signal

void	signalhandler(int sig, siginfo_t *info, void *context)
{
	int					bit;
	static int			i;
	unsigned char		c;

	(void)context;
	bit = 0;
	if (sig == SIGUSR2)
		bit = 1;
	g_binary[i] = bit;
	kill(info->si_pid, SIGUSR2);
	i++;
	if (i % 8 == 0)
	{
		i = 0;
		c = ft_conversion(g_binary);
		if (c < 128)
			write(1, &c, 1);
		if (c >= 128)
			kill(info->si_pid, SIGUSR1);
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	action;

	action.sa_sigaction = &signalhandler;
	action.sa_flags = SA_SIGINFO;
	pid = getpid();
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	write(1, "PID = ", 6);
	ft_putnbr(pid);
	write(1, "\n", 1);
	while (1)
		sleep(1);
	return (0);
}
