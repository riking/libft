/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perrorf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 10:12:30 by kyork             #+#    #+#             */
/*   Updated: 2018/05/30 18:05:14 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <ft_printf_export.h>

#include "ft_printf_private.h"
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>

#define PERROR_ERR "<ERROR WHEN PRINTING ERROR REASON>"

PRINTF_FUNC1	ft_perrorf(const char *fmt, ...)
{
	int			errnum;
	va_list		args;
	char		*reason;
	const char	*er;
	int			len;

	errnum = errno;
	va_start(args, fmt);
	len = ft_vasprintf(&reason, fmt, args);
	va_end(args);
	if (len < 0)
		reason = NULL;
	if (len < 0)
		write(2, PERROR_ERR, sizeof(PERROR_ERR) - 1);
	er = sys_errlist[errnum];
	len = ft_dprintf(2, "%s: %s\n", reason, er);
	free(reason);
	return (len);
}
