/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchah <mbenchah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 00:30:35 by mbenchah          #+#    #+#             */
/*   Updated: 2025/03/19 17:16:55 by mbenchah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_parsing(t_vars *var, int ac, char **av)
{
	const char	*type;

	type = av[1];
	var->iter_calcul = iter_calcul;
	if (!ft_strncmp(type, "mandelbrot", 10) && ac == 2 && type[10] == 0)
		var->fract_func = ft_mandelbrot;
	else if (!ft_strncmp(type, "julia", 5))
	{
		if ((ac < 4 || !valid_double(av[2])
				|| !valid_double(av[3])) || ac > 4)
			return (0);
		var->fract_func = julia_pixel;
		var->julia_c.x = ft_atod(av[2]);
		var->julia_c.y = ft_atod(av[3]);
	}
	else
		return (0);
	return (1);
}

static void	print_valid_args(const char *prog_name)
{
	write(1, prog_name, ft_strlen(prog_name));
	ft_putstr_fd(1, " USAGE: ./fractol mandelbrot");
	write(1, prog_name, ft_strlen(prog_name));
	ft_putstr_fd(1, " USAGE: ./fractol julia <r_value> <i_value>");
}

static int	ft_init_mlx(t_vars	*var, t_mlx_data *img)
{
	var->fract_color = fract_color;
	var->win = mlx_new_window(var->mlx, WIDTH, HEIGHT, "fract-ol");
	if (!var->win)
	{
		ft_putstr_fd(2, "mlx_new_window failed");
		return (free(var->mlx), 0);
	}
	img->img = mlx_new_image(var->mlx, WIDTH, HEIGHT);
	if (!img->img)
	{
		mlx_destroy_window(var->mlx, var->win);
		free(var->mlx);
		return (ft_putstr_fd(2, "mlx_new_image failed"), 0);
	}
	img->addr = mlx_get_data_addr(img->img, &img->bpp,
			&img->line_length, &img->endian);
	var->img = img;
	ft_set_map(var);
	mlx_key_hook(var->win, key_hook, var);
	mlx_mouse_hook(var->win, mouse_hook, var);
	mlx_hook(var->win, 17, 0L, destroy_hook, var);
	return (1);
}

int	main(int ac, char **av)
{
	t_vars		var;
	t_mlx_data	data;

	if (HEIGHT <= 0 || WIDTH <= 0)
		return (ft_putstr_fd(2, "HEIGHT END WIDTH must \
			be greater than 0"), 0);
	if (ac < 2 || !ft_parsing(&var, ac, av))
	{
		print_valid_args(av[0]);
		return (0);
	}
	var.mlx = mlx_init();
	if (var.mlx == NULL)
	{
		ft_putstr_fd(2, "mlx init failed");
		return (1);
	}
	if (!ft_init_mlx(&var, &data))
		return (1);
	iterate_image(&var);
	mlx_put_image_to_window(var.mlx, var.win, data.img, 0, 0);
	mlx_loop(var.mlx);
	return (0);
}
