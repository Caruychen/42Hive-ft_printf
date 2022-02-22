/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:36:18 by cchen             #+#    #+#             */
/*   Updated: 2022/02/21 16:01:34 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

int	append_str(t_vec *result, const char *s)
{
	if (s == NULL)
		return (vec_append_str(result, "(null)"));
	return (vec_append_str(result, s));
}

int	get_int_base(const char c)
{
	return (10 + 6 * (c == 'x' || c == 'X') - 2 * (c == 'o'));
}