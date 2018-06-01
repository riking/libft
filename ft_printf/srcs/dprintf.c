/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dprintf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 19:23:04 by kyork             #+#    #+#             */
/*   Updated: 2018/05/31 18:03:12 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_export.h"
#include "ft_printf_private.h"

#include <stdlib.h>
#include <unistd.h>

PRINTF_FUNC1		ft_printf(const char *fmt, ...)
{
	va_list			args;
	int				len;

	va_start(args, fmt);
	len = ft_vdprintf(1, fmt, args);
	va_end(args);
	return (len);
}

EXPORT_INT			ft_vprintf(const char *fmt, va_list args)
{
	return (ft_vdprintf(1, fmt, args));
}

PRINTF_FUNC2		ft_dprintf(int fd, const char *fmt, ...)
{
	va_list			args;
	int				len;

	va_start(args, fmt);
	len = ft_vdprintf(fd, fmt, args);
	va_end(args);
	return (len);
}

EXPORT_INT			ft_vdprintf(int fd, const char *fmt, va_list args)
{
	int				count;
	t_printf_parse	parse;

	ft_printf_setup_parse(&parse, &ft_printf_printer_fd, -1ULL);
	parse.print_data.fd.fd = fd;
	parse.print_data.fd.buf = malloc(FD_BUF_SIZE);
	parse.print_data.fd.used_buf = 0;
	count = (int)ft_do_printf(fmt, args, &parse);
	write(fd, parse.print_data.fd.buf, parse.print_data.fd.used_buf);
	free(parse.print_data.fd.buf);
	return (count);
}
