/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:11:46 by cchen             #+#    #+#             */
/*   Updated: 2022/02/21 16:01:13 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	dispatch_index(const char spec)
{
	if (ft_islower(spec) * (spec - 'a'))
		return (spec - 'a');
	if (ft_isupper(spec))
		return (spec - 'A');
	return (0);
}

int	parse_conversion(t_vec *result, const char **format, t_specs *specs)
{
	specs->spec = **format;
	g_dispatcher[dispatch_index(specs->spec)](result, specs);
	(*format)++;
	return (result->len);
}

int	parse(t_vec *result, const char *format, t_specs specs)
{
	const char	*p;

	p = format;
	while (*p)
	{
		if (*p++ == '%')
		{
			if (vec_append_strn(result, format, (p - 1) - format) < 0)
				return (-1);
			parse_conversion(result, &p, &specs);
			format = p;
		}
	}
	if (vec_append_strn(result, format, p - format) < 0)
		return (-1);
	return (0);
}
