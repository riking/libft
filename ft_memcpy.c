/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 09:29:10 by kyork             #+#    #+#             */
/*   Updated: 2016/09/21 09:34:47 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Keep CPY_TYPE as char to trigger autovectorization (-O3)
*/

#define CPY_TYPE char
#define CPY_WSIZE sizeof( CPY_TYPE )
#define CPY_WMASK (CPY_WSIZE - 1)

void	*ft_memcpy(void *dst, const void *src, size_t length)
{
	size_t	t;
	void	*od;

	if (!src)
		return (dst);
	od = dst;
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
	return (od);
}
