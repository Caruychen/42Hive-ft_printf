/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_modifiers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 23:19:45 by cchen             #+#    #+#             */
/*   Updated: 2022/03/09 15:27:02 by cchen            ###   ########.fr       */
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
	int		sign;
	char	*res;
	char	*tmp;
	size_t	pad_len;
	char	*padding;
	size_t	len;
	char	*offset;

	specs->value = va_arg(specs->ap, int);
	sign = 1 - ((specs->value < 0) * 2);
	if (specs->is_signed)
		specs->value *= sign;
	res = ft_uitoa(specs->value, get_int_base(specs->spec), specs->spec == 'X');
	len = ft_strlen(res);
	if (specs->flags & ZERO)
	{
		specs->precision = ft_imax(specs->width, specs->precision);
		specs->width = 0;
	}
	pad_len = (specs->precision > len) * (specs->precision - len) + (sign < 0 || specs->is_signed);
	pad_len += (specs->width > (pad_len + len)) * (specs->width - (pad_len + len));
	pad_len += specs->spec == 'o' * 1;
	pad_len += ft_tolower(specs->spec) == 'x' * 2;
	padding = ft_strnew(pad_len);
	offset = padding;
	if (specs->flags & HASH && specs->value)
	{
		if (specs->flags & ZERO)
		{
			if (specs->spec == 'o' || ft_tolower(specs->spec) == 'x')
				*offset++ = '0';
			if (ft_tolower(specs->spec) == 'x')
				*offset++ = specs->spec;
			ft_memset(offset, '0', pad_len - (offset - padding));
			offset += specs->width - ft_imax(specs->precision, len + (sign < 0 || specs->is_signed));
		}
		if (!(specs->flags & ZERO))
		{
			ft_memset(padding, ' ', specs->width - ft_imax(specs->precision, len + (sign < 0 || specs->is_signed)));
			offset += specs->width - ft_imax(specs->precision, len + (sign < 0 || specs->is_signed));
			if (specs->spec == 'o' || ft_tolower(specs->spec) == 'x')
				*offset++ = '0';
			if (ft_tolower(specs->spec) == 'x')
				*offset++ = specs->spec;
		}
	}
	*padding = '+' * (sign > 0 && specs->flags & PLUS) + '-' * (sign < 0 && specs->is_signed);
	if (pad_len)
		ft_memset(padding + 1, '0', pad_len - 1);

	tmp = res;
	res = ft_strjoin(padding, res);
	ft_strdel(&tmp);
	ft_strdel(&padding);
	return (res);
}

char	*lengthmod_long(t_specs *specs)
{
	specs->value = va_arg(specs->ap, long);
	if (specs->is_signed)
		return (ft_ltoa(specs->value, 10));
	return (ft_ultoa(specs->value,
			get_int_base(specs->spec), specs->spec == 'X'));
}
