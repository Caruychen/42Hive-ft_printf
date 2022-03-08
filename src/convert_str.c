/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 11:13:57 by cchen             #+#    #+#             */
/*   Updated: 2022/03/08 13:32:10 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	append_char(t_vec *result, t_specs *specs, char c)
{
	int	res;
	if (!(specs->flags & DASH))
		padding(result, specs->width - 1, specs->pad_char);
	res = vec_push(result, &c);
	if (specs->flags & DASH)
		padding(result, specs->width - 1, specs->pad_char);
	return (res);
}

int	conv_char(t_vec *result, t_specs *specs)
{
	char	c;

	c = va_arg(specs->ap, int);
	return (append_char(result, specs, c));
}

int	conv_string(t_vec *result, t_specs *specs)
{
	char	*str;
	size_t	length;

	str = va_arg(specs->ap, char *);
	if (!str)
		str = "(null)";
	length = ft_strlen(str);
	if (specs->precision_on && length > specs->precision)
		length = specs->precision;
	return (vec_append_strn(result, str, length));
}
