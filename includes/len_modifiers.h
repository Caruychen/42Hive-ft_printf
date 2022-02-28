/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_modifiers.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 23:22:57 by cchen             #+#    #+#             */
/*   Updated: 2022/02/28 10:34:46 by cchen            ###   ########.fr       */
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

char	*lengthmod_char(t_specs *specs);
char	*lengthmod_short(t_specs *specs);
char	*lengthmod_int(t_specs *specs);
char	*lengthmod_long(t_specs *specs);

typedef char				*(*t_modifier)(t_specs *);

static const t_modifier		g_modifier[6] = {
	lengthmod_int,
	lengthmod_long,
	lengthmod_short,
	lengthmod_long,
	lengthmod_long,
	lengthmod_char
};

#endif
