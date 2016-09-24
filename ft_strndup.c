/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 18:31:23 by kyork             #+#    #+#             */
/*   Updated: 2016/09/23 20:40:57 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	size_t	len;
	char	*dst;

	len = ft_strlen(s1);
	if (n > len)
		return (0);
	if (len > n)
		len = n;
	dst = ft_strnew(len);
	if (!dst)
		return (0);
	ft_strncpy(dst, s1, len);
	return (dst);
}
