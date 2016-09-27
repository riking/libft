/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 09:29:10 by kyork             #+#    #+#             */
/*   Updated: 2016/09/27 11:56:10 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_memmove_backwards(void *dst, const void *src, size_t length)
{
	size_t	t;

	src += length;
	dst += length;
	t = length / 1;
	while (t > 0)
	{
		src -= 1;
		dst -= 1;
		*(char*)dst = *(char*)src;
		t--;
	}
}

static void	ft_memmove_forwards(void *dst, const void *src, size_t length)
{
	size_t	t;

	t = length / 1;
	while (t > 0)
	{
		*(char*)dst = *(char*)src;
		src += 1;
		dst += 1;
		t--;
	}
}

void		*ft_memmove(void *dst, const void *src, size_t length)
{
	if (src < dst)
		ft_memmove_backwards(dst, src, length);
	else
		ft_memmove_forwards(dst, src, length);
	return (dst);
}
