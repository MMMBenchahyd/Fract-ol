/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_helper1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchah <mbenchah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 00:30:49 by mbenchah          #+#    #+#             */
/*   Updated: 2025/02/27 00:30:52 by mbenchah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_map(const int value, const int max, \
	const double fmin, const double fmax)
{
	return (fmin + ((((double)value) / (double)(max)) * (fmax - fmin)));
}

void	pixel_color(t_mlx_data *data, int x, int y, unsigned int color)
{
	void	*dest;

	dest = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*((unsigned int *)dest) = color;
}

void	ft_exit(const int code, const t_vars *var)
{
	mlx_destroy_image(var->mlx, var->img->img);
	mlx_destroy_window(var->mlx, var->win);
	exit(code);
}
