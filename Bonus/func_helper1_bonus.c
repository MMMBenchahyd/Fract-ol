/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_helper1_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchah <mbenchah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 00:32:13 by mbenchah          #+#    #+#             */
/*   Updated: 2025/03/19 17:10:20 by mbenchah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

double	ft_map(const int value, const int max, \
	const double fmin, const double fmax)
{
	return (fmin + ((((double)value) / (double)(max)) * (fmax - fmin)));
}

void	pixel_color(t_mlx_data *d, int x, int y, unsigned int color)
{
	void	*dest;

	dest = d->addr + (y * d->line_length + x * (d->bits_per_pixel / 8));
	*((unsigned int *)dest) = color;
}

double	ft_abs(const double f)
{
	if (f < 0)
		return (-f);
	return (f);
}

void	exit_program(const int code, const t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img->img);
	mlx_destroy_window(vars->mlx, vars->win);
	exit(code);
}
