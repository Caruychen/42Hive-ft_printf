/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_modifiers.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 23:22:57 by cchen             #+#    #+#             */
/*   Updated: 2022/02/26 23:24:01 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEN_MODIFIERS_H
# define LEN_MODIFIERS_H

# define LEN_FLAG_INDEX_MAX 2

typedef enum e_length
{
	null,
	L,
	h,
	l,
	ll,
	hh,
}	t_length;

char	*lengthmod_uchar(t_specs *specs);
char	*lengthmod_ushort(t_specs *specs);
char	*lengthmod_uint(t_specs *specs);
char	*lengthmod_ulong(t_specs *specs);

typedef char				*(*t_modifier)(t_specs *);

static const t_modifier		g_modifier[6] = {
	lengthmod_uint,
	lengthmod_ulong,
	lengthmod_ushort,
	lengthmod_ulong,
	lengthmod_ulong,
	lengthmod_uchar
};

#endif
