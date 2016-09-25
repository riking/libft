/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ary_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 14:23:42 by kyork             #+#    #+#             */
/*   Updated: 2016/09/24 14:38:40 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_array		*ft_ary_create(size_t sizeof_item)
{
	t_array	*a;

	a = (t_array*)ft_memalloc(sizeof(t_array));
	if (!a)
		return (0);
	*(size_t*)&a->item_size = sizeof_item;
	a->item_count = 0;
	a->item_cap = FT_ARY_DEFAULT_CAP;
	a->ptr = (void*)ft_memalloc(a->item_size * a->item_cap);
	if (!a->ptr)
	{
		free(a);
		return (0);
	}
	return (a);
}
