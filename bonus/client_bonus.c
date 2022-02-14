/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 10:58:19 by xle-boul          #+#    #+#             */
/*   Updated: 2022/02/13 17:49:03 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

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

void	ft_send_terminator(int pid)
{
	static int	i = 0;

	if (i <= 8)
		if (kill(pid, SIGUSR1) == -1)
			ft_error_handler(0);
	i++;
}

void	ft_send_signal(int pid, char *str)
{
	static int	bit = 0;
	static char	*str_bis = 0;

	if (str)
		str_bis = str;
	if (*str_bis)
	{
		if (((*str_bis >> bit) % 2) == 0)
			if (kill(pid, SIGUSR1) == -1)
				ft_error_handler(0);
		if (((*str_bis >> bit) % 2) == 1)
			if (kill(pid, SIGUSR2) == -1)
				ft_error_handler(0);
		bit++;
		if (bit == 8)
		{
			str_bis++;
			bit = 0;
		}
	}
	if (!(*str_bis))
		ft_send_terminator(pid);
}

void	ft_receipt(int sig, siginfo_t *info, void *context)
{
	(void)context ;
	if (sig == SIGUSR1)
		ft_send_signal(info->si_pid, NULL);
	if (sig == SIGUSR2)
	{
		write(1, "Server >> \"The message came through\"\n", 38);
		exit(1);
	}
}

int	main(int ac, char **av)
{
	struct sigaction	action;

	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = ft_receipt;
	if (sigaction(SIGUSR1, &action, NULL) == -1
		|| sigaction(SIGUSR2, &action, NULL) == -1)
		ft_error_handler(1);
	if (ac != 3)
	{
		write(1, "Utilisez le format: ./client <PID> <String>\n", 44);
		exit(EXIT_FAILURE);
	}
	ft_send_signal(ft_atoi(av[1]), av[2]);
	while (1)
		pause();
	return (0);
}
