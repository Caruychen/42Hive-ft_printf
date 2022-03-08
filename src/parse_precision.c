/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 09:52:57 by cchen             #+#    #+#             */
/*   Updated: 2022/03/08 16:16:05 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "dispatch.h"
#include "flags.h"

void	parse_precision(const char **format, t_specs *specs)
{
	if (**format != '.')
		return ;
	specs->precision_on = 1;
	specs->flags &= ~(ZERO);
	specs->pad_char = ' ';
	(*format)++;
	if (**format != '-')
		specs->precision = ft_atoi(*format);
	else
		(*format)++;
	while (ft_isdigit(**format))
		(*format)++;
}
