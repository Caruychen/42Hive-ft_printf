/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:03:47 by cchen             #+#    #+#             */
/*   Updated: 2022/03/14 16:26:00 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "vec.h"
# include "dispatch.h"
# include "modifiers.h"
# include "flags.h"

# define TRUE 1
# define FALSE 0

void	init_specs(t_specs *specs, va_list ap);
void	reset_specs(t_specs *specs);
int		get_int_base(const char c);
int		padding(t_vec *result, int length, char c, int trigger);
int		read_option(const char **format, t_specs *specs);

int		ft_printf(const char *format, ...);
int		ft_vasprintf(char **ret, const char *format, va_list ap);
int		parse(t_vec *result, const char *format, t_specs specs);
int		parse_conversion(t_vec *result, const char **format,
			t_specs *specs);
void	parse_length(const char **format, t_specs *specs);
void	parse_precision(const char **format, t_specs *specs);
void	parse_flags(const char **format, t_specs *specs);
void	parse_width(const char **format, t_specs *specs);

#endif
