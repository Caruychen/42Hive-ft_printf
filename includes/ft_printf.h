/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:03:47 by cchen             #+#    #+#             */
/*   Updated: 2022/02/26 23:26:07 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "vec.h"
# include "dispatch.h"
# include "len_modifiers.h"

# define TRUE 1
# define FALSE 0

int	append_str(t_vec *result, const char *s);
int	get_int_base(const char c);

int	ft_printf(const char *format, ...);
int	ft_vasprintf(char **ret, const char *format, va_list ap);
int	parse(t_vec *result, const char *format, t_specs specs);

#endif
