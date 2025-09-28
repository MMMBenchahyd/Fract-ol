/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchah <mbenchah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 00:30:26 by mbenchah          #+#    #+#             */
/*   Updated: 2025/02/27 23:01:23 by mbenchah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_calc_zoom(t_vars *var, const double factor)
{
	t_vector	deff;

	deff.x = var->map_end.x - var->map_start.x;
	deff.y = var->map_end.y - var->map_start.y;
	var->map_start.x += (deff.x / 2.0) * factor;
	var->map_start.y += (deff.y / 2.0) * factor;
	var->map_end.x -= (deff.x / 2.0) * factor;
	var->map_end.y -= (deff.y / 2.0) * factor;
}

void	ft_set_map(t_vars *var)
{
	var->map_start.x = -2.5 ;
	var->map_start.y = -2.0 ;
	var->map_end.x = 1.5 ;
	var->map_end.y = 2.0 ;
}
