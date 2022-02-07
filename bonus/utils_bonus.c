/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 17:16:23 by xle-boul          #+#    #+#             */
/*   Updated: 2022/02/07 11:01:33 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	ft_atoi(char *str)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (str[i] != '\0')
	{
		if (48 <= str[i] && str[i] <= 57)
		{
			n = n * 10 + str[i] - 48;
			i++;
		}
		else
		{
			write(1, "Le PID est incorrect\n", 21);
			exit(0);
		}
	}
	return (n);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	unsigned int	nb;

	nb = n;
	if (nb >= 10)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + 48);
}
