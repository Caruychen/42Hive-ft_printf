/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:11:46 by cchen             #+#    #+#             */
/*   Updated: 2022/03/08 10:07:50 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	parse(t_vec *result, const char *format, t_specs specs)
{
	const char	*p;

	p = format;
	while (*p)
	{
		if (*p++ == '%')
		{
			reset_specs(&specs);
			if (vec_append_strn(result, format, (p - 1) - format) < 0)
				return (-1);
			parse_flags(&p, &specs);
			parse_width(&p, &specs);
			parse_precision(&p, &specs);
			parse_length(&p, &specs);
			if (parse_conversion(result, &p, &specs) < 0)
				return (-1);
			format = p;
		}
	}
	if (vec_append_strn(result, format, p + 1 - format) < 0)
		return (-1);
	return (0);
}
