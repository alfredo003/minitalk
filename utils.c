/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achivela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 13:09:57 by achivela          #+#    #+#             */
/*   Updated: 2024/07/12 13:10:00 by achivela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

void	is_invalid(int pid)
{
	if (pid == 0)
	{
		ft_printf("PID INVALIDO!\n");
		exit(1);
	}
}

void	header(void)
{
	printf("\033[0;42mSERVER ON\n");
	printf("\033[0;33mPID : %d\n", getpid());
}

void	alert(int res)
{
	if (res == -1)
	{
		ft_printf("\033[0;41mSERVIDOR NÃO ENCONTRADO\n");
		exit(1);
	}
}
