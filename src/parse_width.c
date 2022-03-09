/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 10:07:09 by cchen             #+#    #+#             */
/*   Updated: 2022/03/09 14:21:59 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "dispatch.h"

void	parse_width(const char **format, t_specs *specs)
{
	specs->width = ft_atoi(*format);
	while (ft_isdigit(**format))
		(*format)++;
}
