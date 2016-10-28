/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ary.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 15:12:44 by kyork             #+#    #+#             */
/*   Updated: 2016/10/27 18:43:50 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <ft_printf.h>

void	print_int_ary(t_array *ary)
{
	size_t	i;

	i = 0;
	while (i < ary->item_count)
	{
		ft_putnbr(*(int*)ft_ary_get(ary, i));
		i++;
		if (i < ary->item_count)
			ft_putchar(' ');
	}
	ft_putchar('\n');
}

int		sort_ints(void *a, void *b, size_t size, void *data)
{
	int int_a;
	int int_b;

	(void)data;
	if (size != sizeof(int))
		abort();
	int_a = *(int*)a;
	int_b = *(int*)b;
	ft_printf("compare %d %d\n", int_a, int_b);
	if (int_a < int_b)
		return (-1);
	if (int_a > int_b)
		return (1);
	return (0);
}

#define INT_VALUE(x) ({item = (x); &item;})

void	test1()
{
	t_array		*ary;
	int			item;
	int			fail;
	// 0 1 2 3 4 5 6
	//
	// append(2) 2
	// append(4) 2 4
	// append(7) 2 4 7
	// append(5) 2 4 7 5
	// insert(6) 2 4 7 5 6
	// insert(0) 0 2 4 7 5 6
	// insert(1) 0 1 2 4 7 5 6
	// remove(7) 0 1 2 4 5 6
	// remove(0) 1 2 4 5 6
	// remove(6) 1 2 4 5
	// swap(2,4) 1 4 2 5
	// set(5, 9) 1 4 2 9
	// clear()
	// append(1) 1

	fail = 0;
	ary = malloc(sizeof(t_array));
	*ary = ft_ary_create(sizeof(int));
	ft_ary_append(ary, INT_VALUE(2));
	print_int_ary(ary);
	ft_ary_append(ary, INT_VALUE(4));
	print_int_ary(ary);
	ft_ary_append(ary, INT_VALUE(7));
	print_int_ary(ary);
	ft_ary_append(ary, INT_VALUE(5));
	print_int_ary(ary);
	ft_ary_insert(ary, INT_VALUE(6), 4);
	print_int_ary(ary);
	ft_ary_insert(ary, INT_VALUE(0), 0);
	print_int_ary(ary);
	ft_ary_insert(ary, INT_VALUE(1), 1);
	print_int_ary(ary);
	ft_ary_sort(ary, sort_ints, NULL);
	print_int_ary(ary);
	ft_ary_remove(ary, 4);
	print_int_ary(ary);
	ft_ary_remove(ary, 0);
	print_int_ary(ary);
	ft_ary_remove(ary, ary->item_count - 1);
	print_int_ary(ary);
	ft_ary_swap(ary, 1, 2);
	print_int_ary(ary);
	ft_ary_set(ary, INT_VALUE(9), 3);
	print_int_ary(ary);
	ft_ary_sort(ary, sort_ints, NULL);
	print_int_ary(ary);
	ft_ary_clear(ary);
	print_int_ary(ary);
	ft_ary_append(ary, INT_VALUE(1));
	print_int_ary(ary);
	//
	ft_ary_destroy2(&ary);
	if (fail)
		printf("malloc FAILed\n");
}

void	test2()
{
	t_array	*ary;
	size_t	i;
	int		fail;

	i = 0;
	fail = 0;
	ary = malloc(sizeof(t_array));
	*ary = ft_ary_create(0);
	while (i < 1000000)
	{
		ft_ary_append(ary, 0);
		i++;
		if (ary->item_count != i)
		{
			printf("FAIL sz=%ld want=%ld\n", ary->item_count, i);
			break ;
		}
		if (fail)
		{
			printf("malloc failure\n");
			break ;
		}
	}
	printf("cap=%ld\n", ary->item_cap);
	ft_ary_destroy2(&ary);
}

void	test3()
{
	t_array	ary;
	int		item;
	size_t	i;

	ary = ft_ary_create(sizeof(int));
	while (i < 10)
	{
		ft_ary_append(&ary, INT_VALUE(rand() % 100000));
		i++;
	}
	ft_ary_sort(&ary, sort_ints, NULL);
	print_int_ary(&ary);
	ft_ary_destroy(&ary);
}

int 	main(void)
{
	test1();
	test2();
	test3();
}
