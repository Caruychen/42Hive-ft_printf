/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:36:18 by cchen             #+#    #+#             */
/*   Updated: 2022/03/06 09:10:55 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "vec.h"

int	append_str(t_vec *result, const char *s)
{
	if (s == NULL)
		return (vec_append_str(result, "(null)"));
	return (vec_append_str(result, s));
}

int	get_int_base(const char c)
{
	return (10 + 6 * (c == 'x' || c == 'X') - 2 * (c == 'o'));
}

void	init_specs(t_specs *specs, va_list ap)
{
	va_copy(specs->ap, ap);
	specs->length = 0;
}

void	reset_specs(t_specs *specs)
{
	specs->length = 0;
}

void	padding(t_vec *result, int length)
{
	while (length-- > 0)
		vec_push(result, "0");
}
