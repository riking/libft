/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynstring_appch.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 22:31:38 by kyork             #+#    #+#             */
/*   Updated: 2017/01/25 23:04:04 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dynstring.h"

int		dynstring_appch(t_dynstring *s, char ch)
{
	int		r;

	if (s->cap <= s->len + 1)
		if ((r = dynstring_grow(s, s->cap + 1)) != 0)
			return (r);
	s->str[s->len++] = ch;
	s->str[s->len] = 0;
	if (s->cap < s->len)
		__builtin_trap();
	return (0);
}
