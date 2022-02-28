/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_modifiers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 23:19:45 by cchen             #+#    #+#             */
/*   Updated: 2022/02/28 08:59:35 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char	*lengthmod_uchar(t_specs *specs)
{
	return (ft_ultoa((unsigned char) va_arg(specs->ap, unsigned int),
			get_int_base(specs->spec), specs->spec == 'X'));
}

char	*lengthmod_ushort(t_specs *specs)
{
	return (ft_ultoa((unsigned short) va_arg(specs->ap, unsigned int),
			get_int_base(specs->spec), specs->spec == 'X'));
}

char	*lengthmod_uint(t_specs *specs)
{
	return (ft_ultoa(va_arg(specs->ap, unsigned int),
			get_int_base(specs->spec), specs->spec == 'X'));
}

char	*lengthmod_ulong(t_specs *specs)
{
	return (ft_ultoa(va_arg(specs->ap, unsigned long),
			get_int_base(specs->spec), specs->spec == 'X'));
}
