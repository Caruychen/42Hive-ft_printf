/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 11:13:57 by cchen             #+#    #+#             */
/*   Updated: 2022/03/07 11:14:51 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"
#include "ft_printf.h"

int	conv_char(t_vec *result, t_specs *specs)
{
	char	c;

	c = va_arg(specs->ap, int);
	return (vec_append_strn(result, &c, 1));
}

int	conv_string(t_vec *result, t_specs *specs)
{
	return (append_str(result, va_arg(specs->ap, char *)));
}


