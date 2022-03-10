/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_modifiers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 23:19:45 by cchen             #+#    #+#             */
/*   Updated: 2022/03/10 10:51:35 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char	*lengthmod_char(t_specs *specs)
{
	specs->value = va_arg(specs->ap, int);
	if (specs->is_signed)
		return (ft_itoa((char) specs->value));
	return (ft_uitoa((unsigned char) specs->value,
			get_int_base(specs->spec), specs->spec == 'X'));
}

char	*lengthmod_short(t_specs *specs)
{
	specs->value = va_arg(specs->ap, int);
	if (specs->is_signed)
		return (ft_itoa((short) specs->value));
	return (ft_uitoa((unsigned short) specs->value,
			get_int_base(specs->spec), specs->spec == 'X'));
}

static char	*pad_results(t_specs specs, char *src)
{
	char	*padding;
	char	*res;

	if (specs.value == 0 && !(specs.flags & HASH) && specs.width && !specs.precision)
		*src = ' ';
	padding = mod_width(specs, ft_strlen(src));
	res = ft_strjoin(padding, src);
	ft_strdel(&src);
	ft_strdel(&padding);
	return (res);
}

char	*lengthmod_int(t_specs *specs)
{
	char	*res;

	specs->value = va_arg(specs->ap, int);
	specs->sign = 1 - ((specs->value < 0) * 2);
	if (specs->is_signed)
		specs->value *= specs->sign;
	res = ft_uitoa(specs->value, get_int_base(specs->spec), specs->spec == 'X');
	return (pad_results(*specs, res));
}

char	*lengthmod_long(t_specs *specs)
{
	specs->value = va_arg(specs->ap, long);
	if (specs->is_signed)
		return (ft_ltoa(specs->value, 10));
	return (ft_ultoa(specs->value,
			get_int_base(specs->spec), specs->spec == 'X'));
}
