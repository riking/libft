/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 14:14:26 by kyork             #+#    #+#             */
/*   Updated: 2016/10/19 17:54:27 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"
#include <unistd.h>

int		ft_printf_printer_fd(t_printf_parse *flags, char c)
{
	int tmp;

	if (flags->used_size + 1 < flags->max_print)
	{
		tmp = write(flags->print_data.fd.fd, &c, 1);
		if (tmp < 0)
			return (-1);
		flags->used_size++;
		return (1);
	}
	return (1);
}

int		ft_printf_printer_str(t_printf_parse *flags, char c)
{
	if (flags->used_size + 1 < flags->max_print)
	{
		flags->print_data.str.str[flags->used_size++] = c;
	}
	return (1);
}

int		ft_printf_printer_noop(t_printf_parse *flags, char c)
{
	(void)c;
	flags->used_size++;
	return (1);
}
