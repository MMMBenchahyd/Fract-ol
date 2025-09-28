/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchah <mbenchah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 00:31:13 by mbenchah          #+#    #+#             */
/*   Updated: 2025/02/27 00:37:29 by mbenchah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	iter_calcul(t_vector coordinate, t_vector c)
{
	double	oldx;
	int		it;

	it = 0;
	while (it < MAX_ITER)
	{
		oldx = coordinate.x;
		coordinate.x = coordinate.x * coordinate.x
			- coordinate.y * coordinate.y;
		coordinate.y = 2 * oldx * coordinate.y;
		coordinate.x += c.x;
		coordinate.y += c.y;
		if ((coordinate.x * coordinate.x) + (coordinate.y * coordinate.y) > 4)
			break ;
		it++;
	}
	return (it);
}

void	julia_pixel(t_vars *var, int map_x, int map_y)
{
	t_vector	coordinate;

	coordinate.x = ft_map(map_x, WIDTH, var->map_start.x, var->map_end.x);
	coordinate.y = ft_map(map_y, HEIGHT, var->map_start.y, var->map_end.y);
	draw_pixel(var, (var->iter_calcul)(coordinate, var->julia_c),
		map_x, map_y);
}

void	ft_mandelbrot(t_vars *var, int map_x, int map_y)
{
	int			counter;
	t_vector	coordinate;
	t_vector	c;

	c.x = ft_map(map_x, WIDTH, var->map_start.x, var->map_end.x);
	c.y = ft_map(map_y, HEIGHT, var->map_start.y, var->map_end.y);
	coordinate.x = 0.0;
	coordinate.y = 0.0;
	counter = (var->iter_calcul)(coordinate, c);
	draw_pixel(var, counter, map_x, map_y);
}
