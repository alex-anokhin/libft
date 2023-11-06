/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olanokhi <olanokhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:12:37 by olanokhi          #+#    #+#             */
/*   Updated: 2023/10/20 17:24:46 by olanokhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, int size)
{
	unsigned char	*ptr;

	ptr = s;
	while (size--)
		*ptr++ = 0;
}
