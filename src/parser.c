/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:11:46 by cchen             #+#    #+#             */
/*   Updated: 2022/03/04 16:06:46 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>

static int	dispatch_index(const char spec)
{
	if (ft_islower(spec) * (spec - 'a'))
		return (spec - 'a');
	if (ft_isupper(spec))
		return (spec - 'A');
	return (0);
}

static int	parse_length(const char **format, t_specs *specs)
{
	int	index;

	index = 0;
	while (index < LEN_FLAG_INDEX_MAX)
	{
		if (!(**format == 'h' || **format == 'l' || **format == 'L'))
			return (specs->length);
		if (**format == 'L')
			return (specs->length = 1);
		if (!specs->length)
			specs->length = **format >> 2;
		else
			specs->length = ((**format & 0x0f) >> 2 == specs->length)
				* ~specs->length;
		index++;
		(*format)++;
	}
	return (specs->length);
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
			reset_specs(&specs);
			if (vec_append_strn(result, format, (p - 1) - format) < 0)
				return (-1);
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
