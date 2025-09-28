/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_func_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchah <mbenchah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 00:31:46 by mbenchah          #+#    #+#             */
/*   Updated: 2025/02/27 00:31:50 by mbenchah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static int	key_hook_inner(const int key, t_vars *var)
{
	if (key == KEYCODE_ZERO)
		ft_set_map(var);
	else if (key == KEYCODE_EIGHT)
		var->julia_c.y += 0.1;
	else if (key == KEYCODE_NUMPAD_TWO)
		var->julia_c.y -= 0.1;
	else if (key == KEYCODE_FOUR)
		var->julia_c.x -= 0.1;
	else if (key == KEYCODE_SIX)
		var->julia_c.x += 0.1;
	else if (key == KEYCODE_ONE
		&& var->color_func != fract_color)
		var->color_func = fract_color;
	else if (key == KEYCODE_TWO
		&& var->color_func != fract_color_2)
		var->color_func = fract_color_2;
	else if (key == KEYCODE_THREE
		&& var->color_func != fract_color_3)
		var->color_func = fract_color_3;
	else
		return (0);
	return (1);
}

int	key_hook(int key, t_vars *var)
{
	if (key == KEYCODE_ESC)
	{
		exit_program(0, var);
		return (0);
	}
	else if (key == KEYCODE_PLUS)
		ft_calc_zoom(var, WIDTH / 3, HEIGHT / 3, 0.1);
	else if (key == KEYCODE_MINUS)
		ft_calc_zoom(var, WIDTH / 3, HEIGHT / 3, -0.1);
	else if (key == KEYCODE_UP)
		ft_translate(0, -1.0, var);
	else if (key == KEYCODE_DOWN)
		ft_translate(0, 1.0, var);
	else if (key == KEYCODE_LEFT)
		ft_translate(-1.0, 0, var);
	else if (key == KEYCODE_RIGHT)
		ft_translate(1.0, 0, var);
	else if (!key_hook_inner(key, var))
		return (0);
	iterate_image(var);
	mlx_put_image_to_window(var->mlx, var->win, var->img->img, 0, 0);
	return (0);
}

int	mouse_hook(int mouse_code, int x, int y, t_vars *var)
{
	if (mouse_code == MOUSECODE_SCROLL_DOWN)
		ft_calc_zoom(var, x, y, 0.2);
	else if (mouse_code == MOUSECODE_SCROLL_UP)
		ft_calc_zoom(var, x, y, -0.2);
	else
	{
		var->julia_c.x = x * 0.001;
		var->julia_c.y = y * 0.001;
	}
	iterate_image(var);
	mlx_put_image_to_window(var->mlx, var->win, var->img->img, 0, 0);
	return (0);
}

int	destroy_hook(t_vars	*var)
{
	exit_program(0, var);
	return (0);
}
