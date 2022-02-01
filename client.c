#include "minitalk.h"

int	*ft_convert_to_binary(int ascii)
{
	int		*binary;
	int		i;
	int		n;

	binary = malloc(sizeof(int) * 7);
	if (!binary)
		return (NULL);
	memset(binary, 0, 6);
	n = ascii;
	i = 6;
	while (n > 0)
	{
		binary[i] = n % 2;
		n /= 2;
		i--;
	}
	return (binary);
}

void	ft_send_signal(int pid, char *str)
{
	int	i;
	int	j;
	int	*binary;

	i = 0;
	while (str[i] != '\0')
	{
		binary = ft_convert_to_binary(str[i]);
		j = 0;
		while (j < 7)
		{
			if (binary[j] == 0)
				kill(pid, SIGUSR1);
			if (binary[j] == 1)
				kill(pid, SIGUSR2);
			usleep(50);
			j++;
		}
		free (binary);
		usleep(50);
		i++;
	}
}

int	main(int ac, char *av[])
{
	int		pid;
	char	*str;

	if (ac != 3)
	{
		write(1, "Utilisez le format: ./client <PID> <String>\n", 44);
		return (1);
	}
	else
	{
		pid = ft_atoi(av[1]);
		if (pid <= 0)
		{
			write(1, "Le PID est incorrect\n", 21);
			return (0);
		}
		str = ft_strcpy(av[2]);
		if (!str)
			return (0);
	}
	ft_send_signal(pid, str);
	free(str);
	return (0);
}
