/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 09:54:52 by cchen             #+#    #+#             */
/*   Updated: 2022/03/08 09:56:21 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "dispatch.h"
#include "flags.h"

void	parse_flags(const char **format, t_specs *specs)
{
	while (ft_strchr(FLAGLIST, **format))
	{
		if (**format == '#')
			specs->flags |= HASH;
		else if (**format == '0')
			specs->flags |= ZERO;
		else if (**format == '-')
			specs->flags |= DASH;
		else if (**format == ' ')
			specs->flags |= SPACE;
		else
			specs->flags |= PLUS;
		(*format)++;
	}
	if (specs->flags & DASH)
		specs->flags &= ~(ZERO);
	if (specs->flags & PLUS)
		specs->flags &= ~(SPACE);
}