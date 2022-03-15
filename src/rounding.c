/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rounding.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:14:48 by cchen             #+#    #+#             */
/*   Updated: 2022/03/15 21:52:53 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long double	rounding(long double value, unsigned int precision)
{
	int				is_odd;
	long double		pow;
	long double		up;
	long double		down;

	pow = (long double) ft_pow(10, precision);
	is_odd = (int) ft_fmod(value * pow, 2) % 2;
	if (!precision && !is_odd && ft_fmod(value * pow, 1) - 0.5 == 0.0)
		return (value);
	up = value + 0.5 / pow;
	down = value - 0.5 / pow;
	if ((up - value) > (value - down))
		return (value);
	return (up);
}
