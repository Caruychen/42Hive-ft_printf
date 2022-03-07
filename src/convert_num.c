/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 11:16:11 by cchen             #+#    #+#             */
/*   Updated: 2022/03/07 22:15:09 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	conv_num(t_vec *result, t_specs *specs)
{
	int		res;
	size_t	len;
	char	*s;
	char	spec;

	spec = specs->spec;
	specs->is_signed = (spec == 'i' || spec == 'd');
	s = g_modifier[specs->length](specs);
	if (!s)
		return (-1);
	len = ft_strlen(s);
	padding(result, specs->precision - len);
	res = vec_append_strn(result, s, len);
	ft_strdel(&s);
	return (res);
}
