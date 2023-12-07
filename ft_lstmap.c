/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olanokhi <olanokhi@42heilbronn.student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 19:55:11 by olanokhi          #+#    #+#             */
/*   Updated: 2023/12/07 02:45:32 by olanokhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*temp;
	void	*content;

	new = NULL;
	while (lst)
	{
		if (f)
			content = f(lst->content);
		if (!content)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		temp = ft_lstnew(content);
		if (!temp)
		{
			ft_lstclear(&new, del);
			del(content);
			return (NULL);
		}
		ft_lstadd_back(&new, temp);
		lst = lst->next;
	}
	return (new);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*src_str[3];
	t_list	*src_lst;
	t_list	*tmp;
	t_list	*map;
	int		i;

	src_str[0] = "start";
	src_str[1] = "mid";
	src_str[2] = "end";
	src_lst = NULL;
	i = 0;
	while (i < 3)
	{
		tmp = ft_lstnew(src_str[i]);
		if (tmp)
			ft_lstadd_back(&src_lst, tmp);
		i++;
	}
	map = ft_lstmap(src_lst, ft_strlen, free);
	printf("map: %p\n\n", map);
	while (map && src_lst)
	{
		printf("map_c: %lu\n", map->content);
		printf("src_c: %s\n", src_lst->content);
//		printf("map_n: %p\n", map->next);
//		printf("src_n: %p\n", src_lst->next);
		map = map->next;
		src_lst = src_lst->next;
	}
	return (0);
}*/
