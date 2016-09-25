/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ary_append.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 14:37:55 by kyork             #+#    #+#             */
/*   Updated: 2016/09/24 14:46:12 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_array	*ft_ary_append(t_array *ary, void *item, int *fail)
{
	if (ary->item_count + 1 > ary->item_cap)
	{
		ary = ft_ary_grow(ary, ary->item_cap * FT_ARY_GROW_FACTOR, fail);
		if (*fail)
			return (ary);
	}
	ft_memcpy(((char*)ary->ptr) + (ary->item_size * ary->item_count),
			item, ary->item_size);
	ary->item_count += 1;
	return (ary);
}
