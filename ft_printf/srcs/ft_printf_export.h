/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_export.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 12:31:03 by kyork             #+#    #+#             */
/*   Updated: 2018/05/31 18:02:54 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_EXPORT_H
# define FT_PRINTF_EXPORT_H
# define FT_PRINTF_H

/*
** ^ Prevent the non-export version from being defined
*/

# include <sys/types.h>

# define EXPORT(type) type __attribute__((visibility("default")))
# define PRINTF_FUNC1 EXPORT(int __attribute__((format (printf, 1, 2))))
# define PRINTF_FUNC2 EXPORT(int __attribute__((format (printf, 2, 3))))
# define PRINTF_FUNC3 EXPORT(int __attribute__((format (printf, 3, 4))))
# define EXPORT_INT EXPORT(int)

PRINTF_FUNC1	ft_printf(const char *fmt, ...);
PRINTF_FUNC2	ft_dprintf(int fd, const char *fmt, ...);
PRINTF_FUNC3	ft_snprintf(char *str, size_t size, const char *fmt, ...);
PRINTF_FUNC2	ft_asprintf(char **ret, const char *fmt, ...);

PRINTF_FUNC1	ft_perrorf(const char *reasonfmt, ...);

/*
** Only snprintf() is no-malloc-safe, and only for the following input data:
** Strings only if narrow, Chars only if narrow, Integers only if no precision
** is specified.
**
** ft_printf() and ft_dprintf() allocate space for an output buffer.
** ft_asprintf calls malloc(3) by spec.
*/

# include <stdarg.h>
# if 1

/*
** expose v*printf functions only if stdarg.h has been included
*/

EXPORT_INT		ft_vprintf(const char *fmt, va_list args);
EXPORT_INT		ft_vdprintf(int fd, const char *fmt, va_list args);
EXPORT_INT		ft_vsnprintf(char *str, size_t size,
					const char *fmt, va_list args);
EXPORT_INT		ft_vasprintf(char **ret, const char *fmt, va_list args);

# endif

#endif
