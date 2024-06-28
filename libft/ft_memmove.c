/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achivela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:56:19 by achivela          #+#    #+#             */
/*   Updated: 2024/05/16 17:56:23 by achivela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*char_dest;
	unsigned char	*char_src;
	size_t			i;

	if (dest == NULL)
		return (NULL);
	char_src = (unsigned char *)src;
	char_dest = (unsigned char *)dest;
	i = 1;
	if (dest > src)
	{
		while (i <= n)
		{
			char_dest[n - i] = char_src[n - i];
			i++;
		}
	}
	else
	{
		ft_memcpy(dest, src, n);
	}
	return (dest);
}
