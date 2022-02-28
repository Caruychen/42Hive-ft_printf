/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_modifiers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 23:19:45 by cchen             #+#    #+#             */
/*   Updated: 2022/02/28 10:49:14 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char	*lengthmod_char(t_specs *specs)
{
	if (specs->is_signed)
		return (ft_itoa((char) va_arg(specs->ap, int)));
	return (ft_uitoa((unsigned char) va_arg(specs->ap, int),
			get_int_base(specs->spec), specs->spec == 'X'));
}

char	*lengthmod_short(t_specs *specs)
{
	if (specs->is_signed)
		return (ft_itoa((short) va_arg(specs->ap, int)));
	return (ft_uitoa((unsigned short) va_arg(specs->ap, int),
			get_int_base(specs->spec), specs->spec == 'X'));
}

char	*lengthmod_int(t_specs *specs)
{
	if (specs->is_signed)
		return (ft_itoa(va_arg(specs->ap, int)));
	return (ft_uitoa(va_arg(specs->ap, int),
			get_int_base(specs->spec), specs->spec == 'X'));
}

char	*lengthmod_long(t_specs *specs)
{
	if (specs->is_signed)
		return (ft_ltoa(va_arg(specs->ap, long), 10));
	return (ft_ultoa(va_arg(specs->ap, long),
			get_int_base(specs->spec), specs->spec == 'X'));
}
