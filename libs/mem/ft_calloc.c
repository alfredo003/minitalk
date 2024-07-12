/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achivela <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:25:49 by achivela          #+#    #+#             */
/*   Updated: 2024/07/09 15:25:52 by achivela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*dst;

	if (nmemb != '\0' && size > 4294967295 / nmemb)
		return (0);
	dst = (void *)malloc(nmemb * size);
	if (!dst)
		return (NULL);
	ft_bzero(dst, size * nmemb);
	return (dst);
}
