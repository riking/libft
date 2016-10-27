/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_progname.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 11:31:06 by kyork             #+#    #+#             */
/*   Updated: 2016/10/27 15:44:31 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static char	*g_progname;

void		ft_set_progname(char *argv0)
{
	char *slash;

	slash = 0;
	while (*argv0)
	{
		if (*argv0 == '/')
		{
			slash = argv0;
		}
		argv0++;
	}
	if (slash)
		g_progname = slash + 1;
	else
		g_progname = argv0;
}

const char	*ft_progname(void)
{
	return (g_progname);
}
