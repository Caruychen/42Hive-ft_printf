/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 11:19:45 by cchen             #+#    #+#             */
/*   Updated: 2022/03/07 11:22:17 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	conv_ptr(t_vec *result, t_specs *specs)
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
		ft_strdel(&x_str);
		return (-1);
	}
	length = append_str(result, s);
	ft_strdel(&x_str);
	ft_strdel(&s);
	return (length);
}


