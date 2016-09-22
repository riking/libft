/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 09:01:55 by kyork             #+#    #+#             */
/*   Updated: 2016/08/15 22:55:30 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	char			*d;
	unsigned int	len;

	d = dest;
	len = 0;
	while (*src && len < n)
	{
		*dest++ = *src++;
		len++;
	}
	while (len < n)
	{
		*dest++ = 0;
		len++;
	}
	return (d);
}
