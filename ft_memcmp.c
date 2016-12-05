/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 10:08:57 by kyork             #+#    #+#             */
/*   Updated: 2016/12/05 15:28:18 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *o_s1, const void *o_s2, size_t n)
{
	unsigned const char	*s1;
	unsigned const char	*s2;
	size_t				i;

	s1 = (unsigned const char*)o_s1;
	s2 = (unsigned const char*)o_s2;
	i = 0;
	while (i + sizeof(long) < n)
	{
		if (*(long*)(s1 + i) != *(long*)(s2 + i))
			break ;
		i += sizeof(long);
	}
	while (i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
