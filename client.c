/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achivela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:05:10 by achivela          #+#    #+#             */
/*   Updated: 2024/07/11 12:05:12 by achivela         ###   ########.fr       */
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
		send_content(pid, argv[2]);
		alert(g_result);
	}
	return (0);
}
