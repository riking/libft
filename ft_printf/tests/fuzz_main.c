/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fuzz_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 20:10:09 by kyork             #+#    #+#             */
/*   Updated: 2016/10/21 22:43:09 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE
#include <ft_printf.h>
#include <libft.h>

#include <dyncall.h>

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

static void	do_read(char *buf, ssize_t max_read)
{
	ssize_t read_ret;
	ssize_t count;

	*buf = 0;
	read_ret = 1;
	count = 0;
	while (read_ret == 1)
	{
		read_ret = read(0, buf, 1);
		if (read_ret == 1 && *buf == '\n')
		{
			buf[0] = 0;
			buf[1] = 0;
			buf[2] = 0;
			buf[3] = 0;
			buf[4] = 0;
			buf[5] = 0;
			buf[6] = 0;
			buf[7] = 0;
			return ;
		}
		count++;
		if (count >= max_read - 8)
		{
			buf[0] = 0;
			buf[1] = 0;
			buf[2] = 0;
			buf[3] = 0;
			buf[4] = 0;
			buf[5] = 0;
			buf[6] = 0;
			buf[7] = 0;
			return ;
		}
		buf++;
	}
}

static int		read_one(char *c)
{
	ssize_t read_ret;

	read_ret = read(0, c, 1);
	return (read_ret == 1);
}

int		main(void)
{
	char		fmt[108];
	DCCallVM	*dc;
	char		buf[108];
	char		type;
	int			argCount;

	char		*strout;
	char		*cmpstr;

	int			argInt;
	long long	argLong;
	char		*argStr;

	do_read(fmt, 108);
	dc = dcNewCallVM(4096);
	dcMode(dc, DC_CALL_C_ELLIPSIS);
	dcArgPointer(dc, &strout);
	dcArgPointer(dc, fmt);
	printf("fmt: %s\n", fmt);
	argCount = 0;
	while (read_one(&type) && argCount < 32)
	{
		printf("got type %c\n", type);
		switch (type)
		{
			case 'I':
				do_read(buf, 14 + 8);
				argInt = (int)strtol(buf, NULL, 10);
				dcArgInt(dc, argInt);
				argCount++;
				printf("int: %d\n", argInt);
				break;
			case 'L':
				do_read(buf, 25 + 8);
				argLong = strtoll(buf, NULL, 10);
				dcArgLongLong(dc, argLong);
				argCount++;
				printf("long: %lld\n", argLong);
				break;
			case 'S':
				do_read(buf, 100 + 8);
				argStr = malloc(108);
				memcpy(argStr, buf, 108);
				dcArgPointer(dc, argStr);
				argCount++;
				printf("string: %s\n", argStr);
				break;
			case 'P':
				do_read(buf, 17 + 8);
				buf[16] = 0;
				argLong = strtoll(buf, NULL, 16);
				dcArgPointer(dc, (void*)(uintptr_t)argLong);
				argCount++;
				printf("pointer: %p\n", (void*)(uintptr_t)argLong);
				break;
		}
	}
	int ret = dcCallInt(dc, &ft_asprintf);
	cmpstr = strout;
	int stdlibRet = dcCallInt(dc, &asprintf);
	int fail = 0;

	if (ret != stdlibRet)
		fail = 1;
	else if (0 != strncmp(cmpstr, strout, stdlibRet))
	{
		fail = 1;
	}

	if (fail)
	{
		printf("FAILURE\n");
		printf("You [%d]: %s\n", ret, cmpstr);
		printf("Lib [%d]: %s\n", stdlibRet, strout);
		abort();
	}
	dcFree(dc);
	printf("%s\n", strout);
	return (0);
}
