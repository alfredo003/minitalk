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

char	*get_next_line(int fd)
{
	int				i;
	char			*buffer;
	static char		*total[4096];

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0))
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (slash_not_found(total[fd]))
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == 0)
			break ;
		buffer[i] = '\0';
		total[fd] = add_to_dest(total[fd], buffer);
	}
	free(buffer);
	buffer = str_to_first_n(total[fd]);
	total[fd] = put_rest_in_total(total[fd]);
	if (buffer && buffer[0] == '\0')
	{
		free(buffer);
		free(total[fd]);
		buffer = NULL;
	}
	return (buffer);
}
