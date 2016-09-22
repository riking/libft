/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 09:23:48 by kyork             #+#    #+#             */
/*   Updated: 2016/09/21 18:48:56 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

typedef char* t_testcase[3];

t_testcase g_testcases[] = {
	{"Beginning of string", "Begin", "Beginning of string"},
	{"End of string\0a", "ing\0b", "ing"},
	{"Matches twice twice", "twice", "twice twice"},
	{"Empty search", "", "Empty search"},
	{"Not found", "pineapple", 0},
	{"worl hahahahoha", "haho", "hahoha"},
};

int		main(void)
{
	int		i;
	char	*result;
	char	*stdlib;

	i = 0;
	while (i < (int)(sizeof(g_testcases) / sizeof(t_testcase)))
	{
		result = ft_strstr(g_testcases[i][0], g_testcases[i][1]);
		stdlib = strstr(g_testcases[i][0], g_testcases[i][1]);
		if (stdlib && result)
		{
			if (strcmp(stdlib, result))
			{
				printf("strstr('%s', '%s')\n", g_testcases[i][0],
						g_testcases[i][1]);
				printf("Lib: %s\nYou: %s\n", stdlib, result);
				printf("FAIL\n");
			}
		}
		else if ((!!stdlib) ^ (!!result))
		{
			printf("strstr('%s', '%s')\n", g_testcases[i][0],
					g_testcases[i][1]);
			printf("Lib: %s\nYou: %s\n", stdlib, result);
			printf("FAIL\n");
		}
		i++;
	}
	printf("Done\n");
	return (0);
}
