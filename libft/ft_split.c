/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhrir <obouhrir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 10:23:40 by obouhrir          #+#    #+#             */
/*   Updated: 2022/10/20 18:04:28 by obouhrir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(char const *s, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			while (s[i] && s[i] != c)
			{
				i++;
			}
			word++;
		}
	}
	return (word);
}

static long	size(char const	*s, char c)
{
	long	i;

	i = 0;
	while (s[i] && s[i] != c)
	{
		i++;
	}
	return (i);
}

char	**ft_split(char const	*s, char c)
{
	char	**res;
	int		j;
	int		k;

	res = (char **)malloc((count(s, c) + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	j = 0;
	while (*s)
	{
		k = 0;
		while (*s && *s == c)
			s++;
		if (*s)
		{
			res[j] = (char *)malloc((size(s, c) + 1) * sizeof(char));
			while (*s && *s != c)
			{
				res[j][k++] = *s++;
			}
			res[j++][k] = '\0';
		}
	}
	res[j] = NULL;
	return (res);
}
