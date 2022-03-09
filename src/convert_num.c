/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 11:16:11 by cchen             #+#    #+#             */
/*   Updated: 2022/03/09 14:46:37 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static inline int	is_null_precision(t_specs specs)
{
	return (specs.precision_on && !(specs.spec == 'o' && specs.flags & HASH)
		&& specs.precision == 0 && specs.value == 0);
}

static int	push_result(t_vec *result, t_specs specs, char *s)
{
	int		res;
	size_t	len;

	len = !is_null_precision(specs) * ft_strlen(s);
	/*
	if (specs.flags & HASH)
	{
		if (specs.spec == 'o')
		{
			specs.width--;
			specs.precision--;
		}
		if (ft_tolower(specs.spec) == 'x')
			specs.width -= 2;
	}
	specs.width -= ft_imax(specs.precision, len);
	if (specs.flags & HASH && specs.flags & ZERO && specs.value)
	{
		if (specs.spec == 'o' || ft_tolower(specs.spec) == 'x')
			vec_push(result, "0");
		if (ft_tolower(specs.spec) == 'x')
			vec_push(result, &specs.spec);
	}
	if (!(specs.flags & DASH))
		padding(result, specs.width, specs.pad_char);
	if (specs.flags & HASH && !(specs.flags & ZERO) && specs.value)
	{
		if (specs.spec == 'o' || ft_tolower(specs.spec) == 'x')
			vec_push(result, "0");
		if (ft_tolower(specs.spec) == 'x')
			vec_push(result, &specs.spec);
	}
	*/
	res = vec_append_strn(result, s, len);
	if (specs.flags & DASH)
		padding(result, specs.width, specs.pad_char);
	return (res);
}

int	conv_num(t_vec *result, t_specs *specs)
{
	int		res;
	char	*s;
	char	spec;

	spec = specs->spec;
	specs->is_signed = (spec == 'i' || spec == 'd');
	s = g_modifier[specs->length](specs);
	if (!s)
		return (-1);
	res = push_result(result, *specs, s);
	ft_strdel(&s);
	return (res);
}
