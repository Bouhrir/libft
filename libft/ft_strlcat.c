/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhrir <obouhrir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 09:52:34 by obouhrir          #+#    #+#             */
/*   Updated: 2022/10/20 13:05:14 by obouhrir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	lens;
	size_t	lend;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!dst && dstsize == 0)
		return (0);
	lend = ft_strlen(dst);
	lens = ft_strlen(src);
	if (lend >= dstsize)
		return (dstsize + lens);
	j = lend;
	while (src[i] != '\0' && j < dstsize - 1)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (lend + lens);
}
