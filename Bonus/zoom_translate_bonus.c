/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_translate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchah <mbenchah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 00:31:33 by mbenchah          #+#    #+#             */
/*   Updated: 2025/02/27 03:04:45 by mbenchah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	ft_translate(double x, double y, t_vars *var)
{
	t_vector			deff;
	double				factor;

	factor = 0.1;
	deff.x = var->map_end.x - var->map_start.x;
	deff.y = var->map_end.y - var->map_start.y;
	var->map_start.x += x * (deff.x / 2.0) * factor;
	var->map_end.x += x * (deff.x / 2.0) * factor;
	var->map_start.y += y * (deff.y / 2.0) * factor;
	var->map_end.y += y * (deff.y / 2.0) * factor;
}

void	ft_calc_zoom(t_vars *var, int x, int y, const double factor)
{
	t_vector	deff;
	t_vector	pos_act;

	pos_act.x = ((double)x / (double)WIDTH);
	pos_act.y = ((double)y / (double)HEIGHT);
	deff.x = var->map_end.x - var->map_start.x;
	deff.y = var->map_end.y - var->map_start.y;
	var->map_start.x += (deff.x) * pos_act.x * factor;
	var->map_start.y += (deff.y) * pos_act.y * factor;
	var->map_end.x -= (deff.x) * (1.0 - pos_act.x) * factor;
	var->map_end.y -= (deff.y) * (1.0 - pos_act.y) * factor;
}

void	ft_set_map(t_vars *var)
{
	var->map_start.x = -3.0 ;
	var->map_start.y = -3.0 ;
	var->map_end.x = 3.0 ;
	var->map_end.y = 3.0 ;
}
