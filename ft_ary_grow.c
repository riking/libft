/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ary_grow.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 14:27:54 by kyork             #+#    #+#             */
/*   Updated: 2016/09/24 16:38:50 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** an ary with item_cap == 0 is a view of existing memory and cannot be grown
*/

t_array		*ft_ary_grow(t_array *ary, size_t min_item_cap, int *fail)
{
	void	*newptr;

	if (ary->item_cap == 0)
	{
		*fail = 1;
		return (ary);
	}
	if (min_item_cap < ary->item_cap)
		return (ary);
	newptr = (void*)malloc(ary->item_size * min_item_cap);
	if (!newptr)
	{
		*fail = 1;
		return (ary);
	}
	ft_memcpy(newptr, ary->ptr, ary->item_size * ary->item_count);
	free(ary->ptr);
	ary->ptr = newptr;
	ary->item_cap = min_item_cap;
	return (ary);
}
