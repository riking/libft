/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 12:58:03 by kyork             #+#    #+#             */
/*   Updated: 2016/08/16 12:04:17 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Return value is length of dst plus length of src, BUT
**   if dst is longer than size, we use that as dst's length
**     and don't copy anything (*1)
** The "space left" is the size parameter minus length of dst
** If there's no space left, don't copy anything (*1)
** While there's at least 1 character of space left, copy
** Keep counting the length of src
** Place the null character at the end
** return dst length + src length
*/

unsigned int	ft_strlcat__strlen(char *str)
{
	char *s;

	s = str;
	while (*s)
		s++;
	return (s - str);
}

unsigned int	ft_strlcat(char *dst, char *src, unsigned int size)
{
	unsigned int	dstsize;
	unsigned int	space_left;
	char			*d;
	char			*s;

	d = dst;
	space_left = size;
	while (*d && space_left-- != 0)
		d++;
	dstsize = (d - dst);
	space_left = size - dstsize;
	if (space_left <= 0)
		return (size + ft_strlcat__strlen(src));
	s = src;
	while (*s && space_left-- > 1)
		*d++ = *s++;
	while (*s)
		s++;
	*d = 0;
	return (dstsize + (s - src));
}
