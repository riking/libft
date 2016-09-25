/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ary_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 14:53:13 by kyork             #+#    #+#             */
/*   Updated: 2016/09/24 16:46:22 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_array		*ft_ary_clear(t_array *ary, int *fail)
{
	void	*newptr;

	newptr = malloc(ary->item_size * FT_ARY_DEFAULT_CAP);
	if (!newptr)
	{
		*fail = 1;
		return (ary);
	}
	free(ary->ptr);
	ary->ptr = newptr;
	ary->item_count = 0;
	ary->item_cap = FT_ARY_DEFAULT_CAP;
	return (ary);
}
