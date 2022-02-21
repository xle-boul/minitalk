/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   characters_generator.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 11:18:56 by xle-boul          #+#    #+#             */
/*   Updated: 2022/02/21 21:18:02 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "minitalk.h"

int	main(int ac, char *av[])
{
	int				number;
	unsigned char	ascii;

	ascii = 127;
	printf("%c\n", ascii);
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
			ascii = 127;
	}
	write(1, "\"", 1);
	return (0);
}
