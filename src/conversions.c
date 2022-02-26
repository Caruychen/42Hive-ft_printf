/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 11:13:37 by cchen             #+#    #+#             */
/*   Updated: 2022/02/26 23:19:25 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	parse_char(t_vec *result, t_specs *specs)
{
	char	c;

	c = va_arg(specs->ap, int);
	return (vec_append_strn(result, &c, 1));
}

int	parse_string(t_vec *result, t_specs *specs)
{
	return (append_str(result, va_arg(specs->ap, char *)));
}

int	parse_num(t_vec *result, t_specs *specs)
{
	int		length;
	char	*s;

	s = ft_itoa(va_arg(specs->ap, int));
	if (!s)
		return (-1);
	length = append_str(result, s);
	free(s);
	return (length);
}

int	parse_unum(t_vec *result, t_specs *specs)
{
	int		length;
	char	*s;

	s = g_modifier[specs->length](specs);
	if (!s)
		return (-1);
	length = append_str(result, s);
	free(s);
	return (length);
}

int	parse_ptr(t_vec *result, t_specs *specs)
{
	int		length;
	char	*x_str;
	char	*s;

	x_str = ft_ultoa(va_arg(specs->ap, uintptr_t), 16, FALSE);
	if (!x_str)
		return (-1);
	s = ft_strjoin("0x", x_str);
	if (!s)
	{
		free(x_str);
		return (-1);
	}
	length = append_str(result, s);
	free(x_str);
	free(s);
	return (length);
}
