/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 21:57:33 by cchen             #+#    #+#             */
/*   Updated: 2022/03/10 10:16:32 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

char	*mod_sign(t_specs specs, int sign)
{
	size_t	len;
	char	*res;

	len = ((specs.is_signed && (specs.flags & 24 || sign < 0)));
	res = ft_strnew(len);
	if (specs.flags & SPACE && sign > 0)
		specs.sign = ' ';
	if (len)
		*res = specs.sign;
	return (res);
}

char	*mod_altform(t_specs specs)
{
	char	*res;

	res = ft_strnew(2);
	if (!(specs.flags & HASH) || specs.is_signed || !specs.value)
		return (res);
	*res = '0';
	if (specs.spec == 'x' || specs.spec == 'X')
		res[1] = specs.spec;
	return (res);
}

char	*mod_precision(t_specs specs, size_t src_len, int sign)
{
	size_t	len;
	char	*res;
	char	*sign_str;
	char	*tmp;

	sign_str = mod_sign(specs, sign);
	src_len += (specs.flags & HASH && specs.spec == 'o' && specs.value);
	src_len += (specs.flags & ZERO && *sign_str);
	len = (specs.precision > src_len) * (specs.precision - src_len);
	tmp = ft_strnew(len);
	ft_memset(tmp, '0', len);
	res = ft_strjoin(sign_str, tmp);
	ft_strdel(&tmp);
	ft_strdel(&sign_str);
	return (res);
}

static char	*prepend_width(t_specs specs, char *src, size_t offset)
{
	size_t	len;
	char	*res;
	char	*tmp;

	len = (specs.width > offset) * (specs.width - offset);
	tmp = ft_strnew(len);
	ft_memset(tmp, ' ', len);
	res = ft_strjoin(tmp, src);
	ft_strdel(&tmp);
	ft_strdel(&src);
	return (res);
}

char	*mod_width(t_specs specs, size_t src_len, int sign)
{
	char	*res;
	char	*alt;
	char	*tmp;
	size_t	altlen;

	alt = mod_altform(specs);
	altlen = ft_strlen(alt);
	if (specs.flags & ZERO)
	{
		if (specs.spec == 'o')
			altlen = 0;
		specs.precision = (specs.width > altlen) * (specs.width - altlen);
		specs.width = 0;
	}
	tmp = mod_precision(specs, src_len, sign);
	res = ft_strjoin(alt, tmp);
	ft_strdel(&alt);
	ft_strdel(&tmp);
	if (specs.flags & DASH)
		return (res);
	return (prepend_width(specs, res, src_len + ft_strlen(res)));
}
