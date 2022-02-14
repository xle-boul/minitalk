/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   characters_generator.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 11:18:56 by xle-boul          #+#    #+#             */
/*   Updated: 2022/02/14 11:50:16 by xle-boul         ###   ########.fr       */
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
	write(1, "\"", 1);
	while (number)
	{
		if (32 <= ascii && ascii <= 126)
		{
			if (!(ascii == 34 || ascii == 33 || ascii == 96 || ascii == 59))
			{
				write(1, &ascii, 1);
				number--;
			}
		}
		ascii--;
		if (ascii == 32)
			ascii = 122;
	}
	write(1, "\"", 1);
	return (0);
}
