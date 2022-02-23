/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:11:46 by cchen             #+#    #+#             */
/*   Updated: 2022/02/23 08:35:04 by cchen            ###   ########.fr       */
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
	t_dispatcher	dispatch;

	specs->spec = *(*format)++;
	dispatch = g_dispatcher[dispatch_index(specs->spec)];
	if (!dispatch)
	{
		if (specs->spec == '%')
			return (vec_push(result, "%"));
		vec_free(result);
		return (-1);
	}
	return (dispatch(result, specs));
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
			if (parse_conversion(result, &p, &specs) < 0)
				return (-1);
			format = p;
		}
	}
	if (vec_append_strn(result, format, p + 1 - format) < 0)
		return (-1);
	return (0);
}
