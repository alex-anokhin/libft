/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olanokhi <olanokhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:12:37 by olanokhi          #+#    #+#             */
/*   Updated: 2023/10/20 15:33:19 by olanokhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	i;
	size_t	multi;

	i = 0;
	multi = nmemb * size;
	if (multi > SIZE_MAX || (nmemb > 0 && size > SIZE_MAX / nmemb))
		return (NULL);
	ptr = malloc(multi);
	if (ptr == NULL)
		return (NULL);
	while (i < (multi))
		((unsigned char *)ptr)[i++] = 0;
	return (ptr);
}
/*
#include <strings.h>
int	main()
{
	size_t	nmemb = INT8_MAX;
	size_t	size = INT8_MAX;
	
	if (!strcmp(ft_calloc(nmemb, size), calloc(nmemb, size)))
		printf("OK\nft: %p\nor: %p\n", ft_calloc(nmemb, size), calloc(nmemb, size));
	else
	{
		printf("ft: %p\nor: %p\n", ft_calloc(nmemb, size), calloc(nmemb, size));
	}
}*/
