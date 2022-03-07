/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 11:15:21 by cchen             #+#    #+#             */
/*   Updated: 2022/03/07 15:22:45 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPATCH_H
# define DISPATCH_H

typedef struct s_specs
{
	va_list				ap;
	char				spec;
	unsigned int		length : 3;
	unsigned int		is_signed : 1;
	unsigned int		flags: 5;
}	t_specs;

int	conv_char(t_vec *result, t_specs *specs);
int	conv_string(t_vec *result, t_specs *specs);
int	conv_num(t_vec *result, t_specs *specs);
int	conv_ptr(t_vec *result, t_specs *specs);
int	conv_flt(t_vec *result, t_specs *specs);

typedef int					(*t_dispatcher)(t_vec *, t_specs *);

static const t_dispatcher	g_dispatcher[26] = {
	NULL,
	NULL,
	conv_char,
	conv_num,
	NULL,
	conv_flt,
	NULL,
	NULL,
	conv_num,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	conv_num,
	conv_ptr,
	NULL,
	NULL,
	conv_string,
	NULL,
	conv_num,
	NULL,
	NULL,
	conv_num,
	NULL,
	NULL,
};

#endif
