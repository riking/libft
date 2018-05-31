/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 12:31:03 by kyork             #+#    #+#             */
/*   Updated: 2018/05/30 18:05:39 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <sys/types.h>

# define PRINTF_FUNC1 int __attribute__((format (printf, 1, 2)))
# define PRINTF_FUNC2 int __attribute__((format (printf, 2, 3)))
# define PRINTF_FUNC3 int __attribute__((format (printf, 3, 4)))

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

# if defined(_VA_LIST) || defined(va_arg)

/*
** expose v*printf functions only if stdarg.h has been included
*/

int				ft_vprintf(const char *fmt, va_list args);
int				ft_vdprintf(int fd, const char *fmt, va_list args);
int				ft_vsnprintf(char *str, size_t size,
					const char *fmt, va_list args);
int				ft_vasprintf(char **ret, const char *fmt, va_list args);

# endif

#endif
