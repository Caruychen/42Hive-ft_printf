/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fmod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 15:59:43 by cchen             #+#    #+#             */
/*   Updated: 2022/03/03 09:00:18 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"
#include <stdio.h>

double	ft_fmod(double x, double y)
{
	t_dcast		ux;
	t_dcast		uy;
	int			ex;
	int			ey;
	int			sx;
	uint64_t	i;

	ux.d = x;
	uy.d = y;
	ex = ux.u >> 52 & 0x7ff;
	ey = uy.u >> 52 & 0x7ff;
	sx = ux.u >> 63;

	/* normalise */
	ux.u &= ~0xfff0000000000000ULL;
	ux.u |= 1ULL << 52;
	uy.u &= ~0xfff0000000000000ULL;
	uy.u |= 1ULL << 52;

	/* x mod y */
	while (ex > ey)
	{
		i = ux.u - uy.u;
		printf("%lld, %lld, %lld\n", ux.u, uy.u, i);
		if (i >> 63 == 0)
		{
			if (i == 0)
				return (0*x);
			ux.u = i;
		}
		printf("after: %lld\n", ux.u);
		ux.u <<= 1;
		printf("shifted: %lld\n", ux.u);
		ex--;
	}
	i = ux.u - uy.u;
	if (i >> 63 == 0)
	{
		printf("%lld\n", ux.u);
		if (i == 0)
			return (0*x);
		ux.u = i;
	}
	printf("%lld, exbefore: %d\n", ux.u, ex);
	while (ux.u >> 52 == 0)
	{
		ux.u <<= 1;
		ex--;
	}
	printf("%lld, exafter: %d\n", ux.u << 12, ex);
	if (ex > 0)
	{
		ux.u -= 1ULL << 52;
		ux.u |= (uint64_t) ex << 52;
	}
	else
		ux.u >>= -ex + 1;
	ux.u |= (uint64_t) sx << 63;
	printf("%lld\n", ux.u << 12);
	return (ux.d);
}
