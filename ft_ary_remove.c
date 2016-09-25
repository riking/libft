/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ary_remove.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 15:09:11 by kyork             #+#    #+#             */
/*   Updated: 2016/09/24 16:41:45 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_array		*ft_ary_remove(t_array *ary, size_t idx)
{
	if (ary->item_cap == 0)
		return (ary);
	if (idx >= ary->item_count)
		return (ary);
	ft_memmove(((char*)ary->ptr) + (idx * ary->item_size),
				((char*)ary->ptr) + ((idx + 1) * ary->item_size),
				(ary->item_count - 1 - idx) * ary->item_size);
	ary->item_count -= 1;
	return (ary);
}
