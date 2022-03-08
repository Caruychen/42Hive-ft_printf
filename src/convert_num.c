/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 11:16:11 by cchen             #+#    #+#             */
/*   Updated: 2022/03/08 13:11:29 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static inline int	is_null_precision(t_specs specs)
{
	return (specs.precision_on && specs.precision == 0 && specs.value == 0);
}
int	conv_num(t_vec *result, t_specs *specs)
{
	int		res;
	size_t	len;
	char	*s;
	char	spec;

	spec = specs->spec;
	specs->is_signed = (spec == 'i' || spec == 'd');
	s = g_modifier[specs->length](specs);
	if (!s)
		return (-1);
	len = !is_null_precision(*specs) * ft_strlen(s);
	padding(
		result,
		specs->width - (ft_imax(specs->precision, len)),
		specs->pad_char);
	padding(result, specs->precision - len, '0');
	res = vec_append_strn(result, s, len);
	ft_strdel(&s);
	return (res);
}
