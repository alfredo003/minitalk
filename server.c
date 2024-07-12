/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achivela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 13:45:00 by achivela          #+#    #+#             */
/*   Updated: 2024/07/11 13:45:02 by achivela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

void	header(void)
{
	printf("\033[0;42mSERVER ON\n");
	printf("\033[0;33mPID : %d\n", getpid());
}

void	listen(int signal, siginfo_t *info, void *uc)
{
	static unsigned char	caracter;
	static int				bit;

	(void)uc;
	(void)info;
	caracter |= (signal == SIGUSR1);
	bit++;
	if (bit == 8)
	{
		if (caracter == '\0')
			write(1, "\n", 1);
		else
			write(1, &caracter, 1);
		caracter = 0;
		bit = 0;
	}
	else
		caracter <<= 1;
}

void	server(void)
{
	struct sigaction	s_sig;

	s_sig.sa_sigaction = &listen;
	sigaction(SIGUSR1, &s_sig, NULL);
	sigaction(SIGUSR2, &s_sig, NULL);
}

int	main(void)
{
	header();
	while (1)
		server();
	return (0);
}
