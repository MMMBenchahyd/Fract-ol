/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchah <mbenchah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 00:30:41 by mbenchah          #+#    #+#             */
/*   Updated: 2025/02/27 00:30:44 by mbenchah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int key, t_vars *var)
{
	if (key == KEYCODE_ESC)
	{
		ft_exit(0, var);
		return (0);
	}
	iterate_image(var);
	return (0);
}

int	mouse_hook(int mouse_code, int a, int b, t_vars *var)
{
	(void)a;
	(void)b;
	if (mouse_code == MOUSECODE_SCROLL_DOWN)
		ft_calc_zoom(var, 0.2);
	if (mouse_code == MOUSECODE_SCROLL_UP)
		ft_calc_zoom(var, -0.2);
	iterate_image(var);
	mlx_put_image_to_window(var->mlx, var->win, var->img->img, 0, 0);
	return (0);
}

int	destroy_hook(t_vars	*var)
{
	ft_exit(0, var);
	return (0);
}
