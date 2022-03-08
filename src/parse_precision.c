/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 09:52:57 by cchen             #+#    #+#             */
/*   Updated: 2022/03/08 09:53:42 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "dispatch.h"

void	parse_precision(const char **format, t_specs *specs)
{
	if (**format != '.')
		return ;
	specs->precision_on = 1;
	(*format)++;
	if (**format != '-')
		specs->precision = ft_atoi(*format);	
	else
		(*format)++;
	while (ft_isdigit(**format))
		(*format)++;
}
