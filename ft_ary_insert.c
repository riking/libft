/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ary_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 14:47:04 by kyork             #+#    #+#             */
/*   Updated: 2016/09/24 15:30:43 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_array		*ft_ary_insert(t_array *ary, void *item,
							size_t idx, int *fail)
{
	if (idx == ary->item_count)
		return (ft_ary_append(ary, item, fail));
	if (ary->item_count + 1 == ary->item_cap)
	{
		ary = ft_ary_grow(ary, ary->item_cap * FT_ARY_GROW_FACTOR, fail);
		if (*fail)
			return (ary);
	}
	ft_memmove(((char*)ary->ptr) + ((idx + 1) * ary->item_size),
			((char*)ary->ptr) + (idx * ary->item_size),
			(ary->item_count - idx) * ary->item_size);
	ft_memcpy(((char*)ary->ptr) + (idx * ary->item_size),
			item,
			ary->item_size);
	ary->item_count += 1;
	return (ary);
}
