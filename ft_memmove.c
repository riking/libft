/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 09:29:10 by kyork             #+#    #+#             */
/*   Updated: 2016/09/21 15:50:51 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Keep CPY_TYPE as char to trigger autovectorization (-O3)
*/

#define CPY_TYPE char
#define CPY_WSIZE sizeof( CPY_TYPE )
#define CPY_WMASK (CPY_WSIZE - 1)

static void	ft_memmove_backwards(void *dst, const void *src, size_t length)
{
	size_t	t;

	src += length;
	dst += length;
	t = length / CPY_WSIZE;
	while (t > 0)
	{
		src -= CPY_WSIZE;
		dst -= CPY_WSIZE;
		*(CPY_TYPE*)dst = *(CPY_TYPE*)src;
		t--;
	}
}

static void	ft_memmove_forwards(void *dst, const void *src, size_t length)
{
	size_t	t;

	t = length / CPY_WSIZE;
	while (t > 0)
	{
		*(CPY_TYPE*)dst = *(CPY_TYPE*)src;
		src += CPY_WSIZE;
		dst += CPY_WSIZE;
		t--;
	}
}

void		*ft_memmove(void *dst, const void *src, size_t length)
{
	if (!src)
		return (dst);
	if (src < dst)
		ft_memmove_backwards(dst, src, length);
	else
		ft_memmove_forwards(dst, src, length);
	return (dst);
}
