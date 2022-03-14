/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 10:07:09 by cchen             #+#    #+#             */
/*   Updated: 2022/03/14 14:09:20 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	parse_width(const char **format, t_specs *specs)
{
	if (**format == '*')
	{
		specs->width = parse_wildcard(specs);
		(*format)++;
		if (!ft_isdigit(**format))
			return ;
	}
	specs->width = ft_atoi(*format);
	while (ft_isdigit(**format))
		(*format)++;
}
