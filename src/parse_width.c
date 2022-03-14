/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 10:07:09 by cchen             #+#    #+#             */
/*   Updated: 2022/03/14 15:51:58 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	parse_width(const char **format, t_specs *specs)
{
	int	arg;

	arg = read_option(format, specs);
	if (arg < 0)
	{
		specs->flags |= DASH;
		specs->flags &= ~(ZERO);
		specs->pad_char = ' ';
	}
	specs->width = (unsigned int) arg * (1 - 2 * (arg < 0));
}
