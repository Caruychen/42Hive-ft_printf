/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_wildcard.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 10:34:38 by cchen             #+#    #+#             */
/*   Updated: 2022/03/14 14:56:34 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dispatch.h"
#include "flags.h"
#include <stdio.h>

unsigned int	parse_wildcard(t_specs *specs)
{
	int	argument;

	argument = va_arg(specs->ap, int);
	if (argument < 0)
	{
		argument *= -1 * !specs->precision_on;
		if (!specs->precision_on)
		{
			specs->flags |= DASH;
			specs->flags &= ~(ZERO);
			specs->pad_char = ' ';
		}
		else
			specs->precision_on = 0;
	}
	return ((unsigned int) argument);
}
