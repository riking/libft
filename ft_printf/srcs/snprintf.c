/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snprintf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 19:23:04 by kyork             #+#    #+#             */
/*   Updated: 2018/05/31 18:03:38 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_export.h"
#include "ft_printf_private.h"

PRINTF_FUNC3		ft_snprintf(char *str, size_t max, const char *fmt, ...)
{
	va_list			args;
	int				len;

	va_start(args, fmt);
	len = ft_vsnprintf(str, max, fmt, args);
	va_end(args);
	return (len);
}

EXPORT_INT			ft_vsnprintf(char *str, size_t max,
		const char *fmt, va_list args)
{
	int				count;
	t_printf_parse	parse;

	ft_printf_setup_parse(&parse, &ft_printf_printer_str, max);
	parse.print_data.str.str = str;
	count = (int)ft_do_printf(fmt, args, &parse);
	if (str)
		str[parse.used_size] = 0;
	return (count);
}
