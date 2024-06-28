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

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*head_a;
	t_list	*map;

	if (!lst)
		return (NULL);
	map = NULL;
	temp = lst;
	while (temp != NULL)
	{
		head_a = ft_lstnew(f(temp->content));
		if (head_a)
			ft_lstadd_back(&map, head_a);
		else
			ft_lstclear(&head_a, del);
		temp = temp->next;
	}
	return (map);
}
