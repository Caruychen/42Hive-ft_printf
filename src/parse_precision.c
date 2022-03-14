/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 09:52:57 by cchen             #+#    #+#             */
/*   Updated: 2022/03/14 11:31:39 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	parse_precision(const char **format, t_specs *specs)
{
	if (**format != '.')
		return ;
	specs->precision_on = 1;
	specs->flags &= ~(ZERO);
	specs->pad_char = ' ';
	(*format)++;
	if (**format == '*')
	{
		specs->precision = parse_wildcard(specs);
		(*format)++;
		return ;
	}
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
