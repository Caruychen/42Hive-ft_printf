/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 11:15:21 by cchen             #+#    #+#             */
/*   Updated: 2022/02/21 12:27:05 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPATCH_H
# define DISPATCH_H

typedef struct s_specs
{
	va_list	ap;
	char	spec;
}	t_specs;


int	parse_char(t_vec *result, t_specs specs);
int	parse_string(t_vec *result, t_specs specs);
int	parse_signed_int(t_vec *result, t_specs specs);
int	parse_uint(t_vec *result, t_specs specs);
int	parse_ptr(t_vec *result, t_specs specs);

typedef int	(*t_dispatcher)(t_vec *, t_specs);

static const t_dispatcher	g_dispatcher[26] = {
	NULL,
	NULL,
	parse_char,
	parse_signed_int,
	NULL,
	NULL,
	NULL,
	NULL,
	parse_signed_int,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	parse_uint,
	parse_ptr,
	NULL,
	NULL,
	NULL,
	NULL,
	parse_uint,
	NULL,
	NULL,
	parse_uint,
	NULL,
	NULL,
};

#endif