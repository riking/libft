/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ary_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 14:27:31 by kyork             #+#    #+#             */
/*   Updated: 2016/10/24 20:36:01 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		sort(t_array *ary, size_t start, size_t len,
		int (*cmp)(void*, void*, size_t))
{
	size_t	lo_storage;
	size_t	idx;
	size_t	pivot_idx;

	if (len <= 1)
		return ;
	pivot_idx = start;
	idx = start + 1;
	lo_storage = start;
	while (idx < start + len)
	{
		if (cmp(ft_ary_get(ary, idx), ft_ary_get(ary, pivot_idx),
					ary->item_size) <= 0)
		{
			ft_ary_swap(ary, idx, ++lo_storage);
		}
		idx++;
	}
	ft_ary_swap(ary, pivot_idx, lo_storage);
	sort(ary, start, lo_storage - start, cmp);
	sort(ary, lo_storage + 1, len - (lo_storage - start) - 1, cmp);
}

void			ft_ary_sort(t_array *ary, int (*cmp)(void*, void*, size_t))
{
	sort(ary, 0, ary->item_count, cmp);
}
