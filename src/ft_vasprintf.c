/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vasprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:39:23 by cchen             #+#    #+#             */
/*   Updated: 2022/02/21 10:19:48 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_vasprintf(char **ret, const char *format, va_list ap)
{
	t_vec	result;
	va_list	ap_cpy;

	if (vec_new(&result, 1, sizeof(char)) < 0)
		return (-1);
	va_copy(ap_cpy, ap);
	if (parse(&result, format, ap) < 0)
		return (-1);
	*ret = result.memory;
	va_end(ap_cpy);
	return (result.len);
}
