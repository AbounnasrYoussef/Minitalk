/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabounna <yabounna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 08:57:12 by yabounna          #+#    #+#             */
/*   Updated: 2025/02/27 14:27:27 by yabounna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "printf/ft_printf.h"

void	reset(unsigned char *caracter_actuelle, int *bit_actuelle)
{
	*caracter_actuelle = 0;
	*bit_actuelle = 0;
}

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static pid_t			pid;
	static unsigned char	caracter_actuelle;
	static int				bit_actuelle;

	(void)context;
	if (pid == 0)
		pid = info->si_pid;
	if (info->si_pid != pid)
		(reset(&caracter_actuelle, &bit_actuelle), pid = info->si_pid);
	if (signum == SIGUSR2)
		caracter_actuelle |= 1 << (7 - bit_actuelle);
	bit_actuelle++;
	if (bit_actuelle == 8)
	{
		if (caracter_actuelle == '\0')
		{
			reset(&caracter_actuelle, &bit_actuelle);
			return ;
		}
		write(1, &caracter_actuelle, 1);
		reset(&caracter_actuelle, &bit_actuelle);
	}
}

int	main(int ac, char **av)
{
	struct sigaction	sig;

	(void) av;
	if (ac != 1)
	{
		ft_printf("use ./server with no args\n");
		return (1);
	}
	ft_printf("Server PID  : %d\n", getpid());
	sig.sa_sigaction = signal_handler;
	sig.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		pause();
	return (0);
}
