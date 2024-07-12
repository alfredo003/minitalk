/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achivela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:27:53 by achivela          #+#    #+#             */
/*   Updated: 2024/07/09 15:27:55 by achivela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

void	ft_print_hex(unsigned int n, const char c)
{
	if (n > 15)
		ft_print_hex(n / 16, c);
	if (c == 'X')
		ft_putchar("0123456789ABCDEF"[n % 16]);
	else
		ft_putchar("0123456789abcdef"[n % 16]);
}
