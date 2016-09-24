/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 13:29:23 by kyork             #+#    #+#             */
/*   Updated: 2016/09/23 22:27:18 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

#define IS_SEP(x) (x == ' ' || x == '\n' || x == '\t')

static void	getbounds(const char **pstr, int *plen)
{
	const char	*str;
	int			len;

	str = *pstr;
	while (str[0] && IS_SEP(str[0]))
		str++;
	len = ft_strlen(str);
	while (len-- > 0)
		if (!IS_SEP(str[len]))
		{
			len++;
			break ;
		}
	*plen = len;
	*pstr = str;
}

char		*ft_strtrim(const char *str)
{
	int		len;
	int		i;
	char	*dest;

	if (!str)
		return (0);
	getbounds(&str, &len);
	dest = ft_strnew(len);
	if (!dest)
		return (0);
	i = 0;
	while (i < len)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}
