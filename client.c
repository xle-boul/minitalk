#include "minitalk.h"
#include <stdio.h>

int	g_binary[8];

// recieves an ascii value (int) and then turns it
// into a binary array of 7 bits and finally flips it
// in the correct order

void	ft_convert_to_binary(int character)
{
	int		i;
	int		j;
	int		bin[8];

	i = 0;
	j = 7;
	while (i < 8)
	{
		bin[i] = character % 2;
		character /= 2;
		g_binary[j] = bin[i];
		i++;
		j--;
	}
}

// sends the ascii value of each character to
// a function that breaks it down to binary
// sends the signal SIGUSR1 if the bit is 0
// sends the signal SIGUSR2 if the bit is 1
// uses usleep in between each signal to give
// time to the server to process before
// getting a new signal

void	ft_send_signal(int pid, char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != '\0')
	{
		ft_convert_to_binary(str[i]);
		j = 0;
		while (j < 8)
		{
			if (g_binary[j] == 0)
				kill(pid, SIGUSR1);
			if (g_binary[j] == 1)
				kill(pid, SIGUSR2);
			usleep(80);
			j++;
		}
		usleep(80);
		i++;
	}
}

// handles the different types of errors that could occur
// recieves the PID and the string as parameters

int	main(int ac, char *av[])
{
	int					pid;

	if (ac != 3)
	{
		write(1, "Utilisez le format: ./client <PID> <String>\n", 44);
		return (-1);
	}
	pid = ft_atoi(av[1]);
	ft_send_signal(pid, av[2]);
	return (0);
}
