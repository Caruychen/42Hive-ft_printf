/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:03:29 by cchen             #+#    #+#             */
/*   Updated: 2022/02/22 14:33:34 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdlib.h>

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	char	*ret;
	int		len;

	va_start(ap, format);
	va_end(ap);
	if (len != -1)
		write(1, ret, len);
	free(ret);
	return (len);
}
