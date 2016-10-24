/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 12:31:03 by kyork             #+#    #+#             */
/*   Updated: 2016/10/18 13:07:43 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <sys/types.h>

int		ft_printf(const char *fmt, ...);
int		ft_dprintf(int fd, const char *fmt, ...);
int		ft_snprintf(char *str, size_t size, const char *fmt, ...);
int		ft_asprintf(char **ret, const char *fmt, ...);

# if defined(_VA_LIST) || defined(va_arg)

/*
** expose v*printf functions only if stdarg.h has been included
*/

int		ft_vprintf(const char *fmt, va_list args);
int		ft_vdprintf(int fd, const char *fmt, va_list args);
int		ft_vsnprintf(char *str, size_t size, const char *fmt, va_list args);
int		ft_vasprintf(char **ret, const char *fmt, va_list args);

# endif

#endif
