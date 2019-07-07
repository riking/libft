/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 13:27:56 by kyork             #+#    #+#             */
/*   Updated: 2016/10/24 09:11:51 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <ft_printf.h>

int		g_correct;
int		g_wrong;

static void	compare_printf(const char *fmt, ...)
{
	va_list 	args;
	va_list		clone;
	int			libret;
	int			youret;
	char		*lib;
	char		*you;

	va_start(args, fmt);
	va_copy(clone, args);
	libret = vasprintf(&lib, fmt, clone);
	va_end(clone);
	printf("Lib [%d]: %s\n", libret, lib);
	va_copy(clone, args);
	youret = ft_vasprintf(&you, fmt, clone);
	va_end(clone);
	va_end(args);

	printf("You [%d]: %s\n", youret, you);
	if (libret != youret || 0 != strcmp(you, lib))
		printf("FAIL\n");
	if (youret != -1 && youret != (int)strlen(you))
		printf("FAIL - string lengths do not match\n");
	free(you);
	free(lib);
}

int			main(void)
{
	wchar_t str[100];

	compare_printf("Bla bla %.3d", 0);
	compare_printf("Bla bla %.10d", 0);
	compare_printf("Bla bla %.20d", 0);
	compare_printf("Bla bla %.30d", 0);
	compare_printf("Hello %c replacement", 221);
	bzero(str, sizeof(str));
	str[0] = 339;
	str[1] = 8721;
	str[2] = 180;
	str[3] = 174;
	str[4] = 8224;
	str[5] = 165;
	str[6] = 168;
	str[7] = 710;
	str[8] = 248;
	str[9] = 960;
	str[10] = 8220;
	str[11] = 8216;
	str[12] = 0;
	compare_printf("%30ls", str);
	compare_printf("% d", 42);
	compare_printf("%+d", 42);
	compare_printf("%+ d", 42);
	compare_printf("% +d", 42);
	compare_printf("%ld", 9223372036854775808UL);
	compare_printf("%lu", 9223372036854775808UL);
	compare_printf("%ld", 9223372036854775807L);
	compare_printf("%lu", 9223372036854775807L);
	compare_printf("%.4S", L"我是一只猫。");
	compare_printf("% #-+010*.*", -15, -15);
	compare_printf("%", -15, -15);
	compare_printf("%#", -15, -15);
	compare_printf("%L.*x", 10, -15);
	compare_printf("%3.*3.*x", 10, -14, 11);


	compare_printf("%hhlx", 0x4200420042004200L);
}
