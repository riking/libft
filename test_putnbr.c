/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 14:21:40 by kyork             #+#    #+#             */
/*   Updated: 2016/09/22 11:36:01 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

char		g_putchar[100];
int			g_putchar_idx = 0;

/*
** Recording version of ft_putchar
*/

void		ft_putchar_fd(char c, int fd)
{
	UNUSED(fd);
	g_putchar[g_putchar_idx++] = c;
}

void		reset_putchar(void)
{
	memset(g_putchar, 0, 100);
	g_putchar_idx = 0;
}

typedef struct {
	int		i;
	char	*s;
}			t_testcase;

t_testcase	g_tests[] = {
	{42, "42"},
	{0, "0"},
	{-1, "-1"},
	{-2147483648, "-2147483648"},
	{-2147483647, "-2147483647"},
	{2147483647, "2147483647"},
	{1000000, "1000000"},
};

int			main(void)
{
	int		i;
	char	*s;

	i = 0;
	while (i < (int)(sizeof(g_tests) / sizeof(t_testcase)))
	{
		reset_putchar();
		ft_putnbr(g_tests[i].i);
		if (VERBOSE || (0 != strcmp(g_tests[i].s, g_putchar)))
			printf("You: %s\nExp: %s\n", g_putchar, g_tests[i].s);
		if (0 != strcmp(g_tests[i].s, g_putchar))
			printf("FAIL\n");
		i++;
	}
	i = 0;
	while (i < (int)(sizeof(g_tests) / sizeof(t_testcase)))
	{
		s = ft_itoa(g_tests[i].i);
		if (VERBOSE || (0 != strcmp(g_tests[i].s, s)))
			printf("You: %s\nExp: %s\n", g_putchar, g_tests[i].s);
		if (0 != strcmp(g_tests[i].s, s))
			printf("FAIL\n");
		free(s);
		i++;
	}
	printf("Done\n");
	return (0);
}
