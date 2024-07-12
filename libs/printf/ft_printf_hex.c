/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achivela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:33:41 by achivela          #+#    #+#             */
/*   Updated: 2024/07/09 15:33:44 by achivela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_printf_hex(unsigned int n, const char c, int *len)
{
	if (n > 15)
		ft_printf_hex(n / 16, c, len);
	if (c == 'X')
		write(1, &"0123456789ABCDEF"[n % 16], 1);
	else
		write(1, &"0123456789abcdef"[n % 16], 1);
	(*len)++;
}

void	ft_print_hexux(unsigned long long n, int *len)
{
	if (n > 15)
		ft_print_hexux(n / 16, len);
	write(1, &"0123456789abcdef"[n % 16], 1);
	(*len)++;
}

void	ft_print_point(unsigned long long p, int *len)
{
	if (p == 0)
	{
		write(1, "(nil)", 5);
		(*len) += 5;
		return ;
	}
	ft_putstr("0x");
	(*len)++;
	(*len)++;
	ft_print_hexux(p, len);
}
