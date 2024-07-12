/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achivela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 12:00:30 by achivela          #+#    #+#             */
/*   Updated: 2024/07/12 12:00:32 by achivela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_result;

void	send_bit(pid_t pid, char caracter)
{
	int	bit;

	bit = 8;
	while (bit--)
	{
		if (caracter & 0x80)
			g_result = kill(pid, SIGUSR1);
		else
			g_result = kill(pid, SIGUSR2);
		caracter <<= 1;
		usleep(500);
	}
}

void	send_content(pid_t pid, char *content)
{
	int	i;

	i = 0;
	while (content[i])
	{
		send_bit(pid, content[i]);
		i++;
	}
	send_bit(pid, '\0');
}

void	mensage(int sinal, siginfo_t *info, void *uc)
{
	(void)uc;
	(void)info;
	if (sinal == SIGUSR1)
	{
		ft_printf("Enviada\n");
		exit(0);
	}
}

void	listen(void)
{
	struct sigaction	s_action;

	s_action.sa_sigaction = &mensage;
	s_action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_action, NULL);
	sigaction(SIGUSR2, &s_action, NULL);
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
		ft_printf("ERRADO!\n");
	else
	{
		pid = ft_atoi(argv[1]);
		if (pid == 0)
		{
			ft_printf("PID INVALIDO!\n");
			exit(1);
		}
		ft_printf("\033[0;35mENVIANDO MENSAGEM AO SERVIDOR ...\n \033[0m");
		listen();
		send_content(pid, argv[2]);
		while (1)
		{
			alert(g_result);
			pause();
		}
	}
	return (0);
}
