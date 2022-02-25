/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vasprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:39:23 by cchen             #+#    #+#             */
/*   Updated: 2022/02/25 13:53:15 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	init_specs(t_specs *specs, va_list ap)
{
	va_copy(specs->ap, ap);
	specs->length = 0;
}

int	ft_vasprintf(char **ret, const char *format, va_list ap)
{
	t_vec	result;
	t_specs	specs;

	if (vec_new(&result, 1, sizeof(char)) < 0)
		return (-1);
	init_specs(&specs, ap);
	if (parse(&result, format, specs) < 0)
		return (-1);
	*ret = result.memory;
	va_end(specs.ap);
	return (result.len - 1);
}
