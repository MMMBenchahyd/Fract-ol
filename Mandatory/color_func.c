/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchah <mbenchah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 00:31:19 by mbenchah          #+#    #+#             */
/*   Updated: 2025/02/27 01:54:47 by mbenchah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	fract_color(const int idx)
{
	const int	colors[20] = {
		0x220066, 0x330066, 0x440077, 0x550088, 0x660099,
		0x550088, 0x440077, 0x330066, 0x220055, 0x110033,
		0xe6f2f9, 0xccffff, 0xb2e6ff, 0x99ddff, 0x80d4ff,
		0x66ccff, 0x4dc3ff, 0x33bbff, 0x1ab2ff, 0x00aaff
	};

	return (colors[idx % 20]);
}

void	draw_pixel(t_vars *var, int idx, int a, int b)
{
	unsigned int	color;

	if (idx == MAX_ITER)
		color = 0;
	else
		color = (var->fract_color)(idx);
	pixel_color(var->img, a, b, color);
}

void	iterate_image(t_vars *var)
{
	int	a;
	int	b;

	b = 0;
	while (b < HEIGHT)
	{
		a = 0;
		while (a < WIDTH)
		{
			(var->fract_func)(var, a, b);
			a++;
		}
		b++;
	}
}
