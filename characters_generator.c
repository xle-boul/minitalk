/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 11:18:56 by xle-boul          #+#    #+#             */
/*   Updated: 2022/02/13 15:22:39 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int ac, char *av[])
{
	int	number;
	int	ascii;

	ascii = 122;
	if (ac != 2)
	{
		write(1, "Format: ./a.out <number>\n", 26);
		return (0);
	}
	number = ft_atoi(av[1]);
	while (number)
	{
		if ((48 <= ascii && ascii <= 57)
			|| (63 <= ascii && ascii <= 90) || (97 <= ascii && ascii <= 122))
		{
			if (ascii == 37)
				ascii--;
			write(1, &ascii, 1);
			number--;
		}
		ascii--;
		if (ascii == 32)
			ascii = 122;
	}
	return (0);
}
