/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabounna <yabounna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 08:57:37 by yabounna          #+#    #+#             */
/*   Updated: 2025/02/28 11:23:34 by yabounna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "printf/ft_printf.h"

static int	check(int s)
{
	if (s == -1)
		return (0);
	return (-1);
}

static int	ft_atoi(const char *str)
{
	int		i;
	long	c;
	int		signe;
	long	tmp;

	i = 0;
	c = 0;
	signe = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+')
		i++;
	if (str[i] == '0')
		return (1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		tmp = c;
		c = c * 10 + (str[i] - '0');
		if (c / 10 != tmp)
			return (check(signe));
		i++;
	}
	if (!str[i])
		return (signe * c);
	return (-1);
}

static void	transfere_signal(int pid, char c)
{
	int	j;

	j = 0;
	while (j < 8)
	{
		if (((c >> (7 - j)) & 1) == 1)
		{
			if (kill (pid, SIGUSR2) == -1)
			{
				write (2, "Sending Error!", 14);
				exit(1);
			}
		}
		else
		{
			if (kill (pid, SIGUSR1) == -1)
			{
				write (2, "Sending Error!", 14);
				exit(1);
			}
		}
		usleep(800);
		j++;
	}
}

int	main(int ac, char **av)
{
	int		i;
	pid_t	pid;

	i = 0;
	if (ac != 3 || ft_atoi(av[1]) == 0)
	{
		ft_printf ("Input no valid \n");
		return (0);
	}
	pid = ft_atoi(av[1]);
	if (pid < 0 || pid > PID_MAX_LIMIT)
		return (write (2, "invalid Pid!", 12));
	while (av[2][i])
	{
		transfere_signal(pid, av[2][i]);
		i++;
	}
	transfere_signal(pid, '\0');
}
