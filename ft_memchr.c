/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 19:06:24 by kyork             #+#    #+#             */
/*   Updated: 2016/09/24 12:42:24 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	void *p;

	p = (void*)s;
	while (n-- > 0)
	{
		if (*(unsigned const char*)p == (unsigned char)c)
			return ((void*)p);
		p++;
	}
	return (NULL);
}
