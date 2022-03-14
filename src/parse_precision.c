/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 09:52:57 by cchen             #+#    #+#             */
/*   Updated: 2022/03/14 14:59:06 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static void	parse_wild(t_specs *specs)
{
	int arg;

	arg = va_arg(specs->ap, int);
	if (arg < 0)
	{
		specs->precision_on = 0;
		return ;
	}
	specs->precision_on = 1;
	specs->flags &= ~(ZERO);
	specs->pad_char = ' ';
	specs->precision = (unsigned int) arg * (arg > 0);
}

void	parse_precision(const char **format, t_specs *specs)
{
	if (**format != '.')
		return ;
	(*format)++;
	if (**format == '*')
	{
		parse_wild(specs);
		(*format)++;
		return ;
	}
	specs->precision_on = 1;
	specs->flags &= ~(ZERO);
	specs->pad_char = ' ';
	if (**format != '-')
		specs->precision = ft_atoi(*format);
	else
	{
		specs->precision_on = 0;
		(*format)++;
	}
	while (ft_isdigit(**format))
		(*format)++;
}
