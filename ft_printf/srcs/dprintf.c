/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 19:23:04 by kyork             #+#    #+#             */
/*   Updated: 2016/10/19 18:00:33 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

int			ft_printf(const char *fmt, ...)
{
	va_list			args;
	int				len;

	va_start(args, fmt);
	len = ft_vdprintf(1, fmt, args);
	va_end(args);
	return (len);
}

int			ft_vprintf(const char *fmt, va_list args)
{
	return (ft_vdprintf(1, fmt, args));
}

int			ft_dprintf(int fd, const char *fmt, ...)
{
	va_list			args;
	int				len;

	va_start(args, fmt);
	len = ft_vdprintf(fd, fmt, args);
	va_end(args);
	return (len);
}

int			ft_vdprintf(int fd, const char *fmt, va_list args)
{
	int				count;
	t_printf_parse	parse;

	ft_printf_setup_parse(&parse, &ft_printf_printer_fd, -1ULL);
	parse.print_data.fd.fd = fd;
	count = (int)ft_do_printf(fmt, args, &parse);
	return (count);
}
