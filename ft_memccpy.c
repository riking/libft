/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 18:38:32 by kyork             #+#    #+#             */
/*   Updated: 2016/09/23 11:22:58 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned const char	*s;
	unsigned char		*d;
	size_t				i;

	if (!src || !dst || n == 0)
		return (dst);
	i = 0;
	d = (unsigned char*)dst;
	s = (unsigned const char*)src;
	while (i < n)
	{
		*d++ = *s;
		if (*s++ == c)
		{
			return (d);
		}
		i++;
	}
	return (NULL);
}
