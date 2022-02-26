/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 11:15:21 by cchen             #+#    #+#             */
/*   Updated: 2022/02/26 23:24:05 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPATCH_H
# define DISPATCH_H

typedef struct s_specs
{
	va_list		ap;
	char		spec;
	unsigned int		length : 3;
}	t_specs;

int	parse_char(t_vec *result, t_specs *specs);
int	parse_string(t_vec *result, t_specs *specs);
int	parse_num(t_vec *result, t_specs *specs);
int	parse_unum(t_vec *result, t_specs *specs);
int	parse_ptr(t_vec *result, t_specs *specs);

typedef int					(*t_dispatcher)(t_vec *, t_specs *);

static const t_dispatcher	g_dispatcher[26] = {
	NULL,
	NULL,
	parse_char,
	parse_num,
	NULL,
	NULL,
	NULL,
	NULL,
	parse_num,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	parse_unum,
	parse_ptr,
	NULL,
	NULL,
	parse_string,
	NULL,
	parse_unum,
	NULL,
	NULL,
	parse_unum,
	NULL,
	NULL,
};

#endif
