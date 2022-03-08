/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_modifiers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 23:19:45 by cchen             #+#    #+#             */
/*   Updated: 2022/03/08 12:57:40 by cchen            ###   ########.fr       */
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

char	*lengthmod_int(t_specs *specs)
{
	specs->value = va_arg(specs->ap, int);
	if (specs->is_signed)
		return (ft_itoa(specs->value));
	return (ft_uitoa(specs->value,
			get_int_base(specs->spec), specs->spec == 'X'));
}

char	*lengthmod_long(t_specs *specs)
{
	specs->value = va_arg(specs->ap, long);
	if (specs->is_signed)
		return (ft_ltoa(specs->value, 10));
	return (ft_ultoa(specs->value,
			get_int_base(specs->spec), specs->spec == 'X'));
}
