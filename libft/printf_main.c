/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achivela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:34:16 by achivela          #+#    #+#             */
/*   Updated: 2024/05/16 18:19:05 by achivela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_printf(const char *str, ...)
{
	va_list	t_args;
	int		str_len;
	int		count;
	int		i;

	if (!str)
		return (0);
	i = -1;
	count = 0;
	str_len = ft_strlen((char *)str);
	va_start(t_args, str);
	while (++i < str_len)
	{
		if (str[i] == '%')
		{
			i += 1;
			while (str[i] == '#')
				i++;
			count += convertions(str, i, t_args);
		}
		else
			count += ft_putchar(str[i]);
	}
	va_end(t_args);
	return (count);
}
