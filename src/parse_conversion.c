/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 09:41:22 by cchen             #+#    #+#             */
/*   Updated: 2022/03/08 13:25:21 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "dispatch.h"

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
			return (append_char(result, specs, '%'));
		vec_free(result);
		return (-1);
	}
	return (dispatch(result, specs));
}
