/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:03:29 by cchen             #+#    #+#             */
/*   Updated: 2022/02/23 08:36:37 by cchen            ###   ########.fr       */
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
	len = ft_vasprintf(&ret, format, ap);
	va_end(ap);
	if (len == -1)
		return (len);
	write(1, ret, len);
	free(ret);
	return (len);
}
