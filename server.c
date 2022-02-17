/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 10:46:38 by xle-boul          #+#    #+#             */
/*   Updated: 2022/02/17 11:19:34 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_error_handler(int i)
{
	if (i == 0)
	{
		write(1, "Error KILL\n", 12);
		exit(1);
	}
	if (i == 1)
	{
		write(1, "Error SIGACTION\n", 17);
		exit(1);
	}
}

void	ft_signal_handler(int sig, siginfo_t *info, void *context)
{
	static unsigned char	val = 0;
	static int				bit = 1;
	static int				id = 0;

	if (info->si_pid != 0)
		id = info->si_pid;
	(void)context ;
	if (sig == SIGUSR1)
		val += 0;
	if (sig == SIGUSR2)
		val += bit;
	bit *= 2;
	if (bit == 256)
	{
		bit = 1;
		if (val == 0)
			if (kill(id, SIGUSR2) == -1)
				ft_error_handler(0);
		if (val != 0)
			write(1, &val, 1);
		val = 0;
	}
	if (kill(id, SIGUSR1) == -1)
		ft_error_handler(0);
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	action;

	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = ft_signal_handler;
	pid = getpid();
	if (sigaction(SIGUSR1, &action, NULL) == -1
		|| sigaction(SIGUSR2, &action, NULL) == -1)
	{
		ft_error_handler(1);
		return (1);
	}
	write(1, "PID = ", 6);
	ft_putnbr(pid);
	write(1, "\n", 1);
	while (1)
		pause();
	return (0);
}
