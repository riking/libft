/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 09:29:10 by kyork             #+#    #+#             */
/*   Updated: 2016/09/27 11:55:08 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t length)
{
	size_t	t;
	void	*od;

	if (length == 0)
		return (dst);
	od = dst;
	src += length;
	dst += length;
	t = length / 1;
	while (t > 0)
	{
		src -= 1;
		dst -= 1;
		*(char*)dst = *(const char*)src;
		t--;
	}
	return (od);
}
