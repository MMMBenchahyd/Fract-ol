/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_func_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchah <mbenchah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 00:32:33 by mbenchah          #+#    #+#             */
/*   Updated: 2025/02/27 00:32:37 by mbenchah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

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

int	fract_color_2(const int idx)
{
	const int	colors[20] = {
		0xff0000, 0xee1100, 0xdd2200, 0xcc3300, 0xbb4400,
		0xaa5500, 0xff6600, 0xee7700, 0xdd8800, 0xcc9900,
		0xffff00, 0xeeff00, 0xddff00, 0xccff00, 0xbbff33,
		0xaaff66, 0x99ff99, 0x88ffaa, 0x77ffbb, 0x66ffcc
	};

	return (colors[idx % 20]);
}

int	fract_color_3(const int idx)
{
	const int	colors[20] = {
		0x0099ff, 0x0088ee, 0x0077dd, 0x0066cc, 0x0055bb,
		0x55ffee, 0x44ffff, 0x33eeff, 0x22ccff, 0x11aaff,
		0x003399, 0x221177, 0x330066, 0x440055, 0x550044,
		0xaaff66, 0x99ff99, 0x88ffaa, 0x77ffbb, 0x66ffcc
	};

	return (colors[idx % 20]);
}

void	draw_pixel(t_vars *var, int idx, int a, int b)
{
	unsigned int	color;

	if (idx == MAX_ITER)
		color = 0;
	else
		color = (*var->color_func)(idx);
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
