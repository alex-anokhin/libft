/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olanokhi <olanokhi@42heilbronn.student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:12:37 by olanokhi          #+#    #+#             */
/*   Updated: 2023/12/07 02:48:41 by olanokhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_split_count(char const *s, char c)
{
	int	i;
	int	w;
	int	count;

	i = 0;
	w = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && w == 0)
		{
			count++;
			w = 1;
		}
		else if (s[i] == c && w == 1)
			w = 0;
		i++;
	}
	return (count);
}

int	get_split_start(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != c)
			return (i);
		i++;
	}
	return (i);
}

int	get_split_len(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (i);
}

char	**free_split(char **str, long n)
{
	while (n >= 0)
		free(str[n--]);
	free(str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	start;
	size_t	len;
	size_t	counts[2];
	char	**splited;

	counts[0] = 0;
	if (s != NULL)
		counts[0] = get_split_count(s, c);
	splited = (char **)malloc((counts[0] + 1) * sizeof(char *));
	if (splited == NULL)
		return (NULL);
	counts[1] = 0;
	start = 0;
	while (counts[1] < counts[0])
	{
		start += get_split_start(s + start, c);
		len = get_split_len(s + start, c);
		splited[counts[1]] = ft_substr(s, start, len);
		if (splited[counts[1]] == NULL)
			return (free_split(splited, counts[1]));
		start += len + 1;
		counts[1]++;
	}
	splited[counts[0]] = NULL;
	return (splited);
}
/*
#include <stdio.h>

int	main(void) {
	char	**tab;
	int		i;

	i = 0;
	if (!(tab = ft_split(NULL, 33)))
        printf("NULL");
    else
    {
        while (tab[i] != NULL)
        {
            printf("%i: %s\n", i+1, tab[i]);
            i++;
        }
    }
	return (0);
}
*/