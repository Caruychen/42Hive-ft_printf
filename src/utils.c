/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:36:18 by cchen             #+#    #+#             */
/*   Updated: 2022/03/08 12:58:21 by cchen            ###   ########.fr       */
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
	reset_specs(specs);
}

void	reset_specs(t_specs *specs)
{
	specs->value = 0;
	specs->length = 0;
	specs->flags = 0;
	specs->precision = 0;
	specs->precision_on = 0;
	specs->width = 0;
	specs->pad_char = ' ';
}

void	padding(t_vec *result, int length, char c)
{
	while (length-- > 0)
		vec_push(result, &c);
}
