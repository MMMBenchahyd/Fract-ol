/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchah <mbenchah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 00:30:12 by mbenchah          #+#    #+#             */
/*   Updated: 2025/03/06 22:33:38 by mbenchah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# include "bottons_bonus.h"
# include <mlx.h>
# include <unistd.h> 
# include <stdlib.h>

# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 200

typedef struct s_mlx_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_mlx_data;

typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;

typedef struct s_vars
{
	void			*mlx;
	void			*win;
	t_mlx_data		*img;
	t_vector		map_start;
	t_vector		map_end;
	t_vector		julia_c;
	int				(*color_func)(const int);
	void			(*fract_func)(struct s_vars *, int, int);
	int				(*iter_calcul)(t_vector, t_vector);
}	t_vars;

void		exit_program(const int code, const t_vars *vars);
void		pixel_color(t_mlx_data *data, int x, int y, unsigned int color);
double		ft_map(const int value, const int max, \
	const double fmin, const double fmax);
double		ft_abs(const double f);

void		ft_calc_zoom(t_vars *var, int x, int y, const double factor);
void		ft_translate(double x, double y, t_vars *var);
void		ft_set_map(t_vars *var);

double		ft_atod(const char *s);
int			valid_double(char *s);
int			ft_parse_args(t_vars *var, int ac, char **av);

void		ft_putstr_fd(const int fd, const char *s);
size_t		ft_strlen(const char *s);
int			ft_strncmp(const char *s1, const char *s2, size_t n);

int			key_hook(int key, t_vars *var);
int			mouse_hook(int mouse_code, int a, int b, t_vars *var);
int			destroy_hook(t_vars	*var);

void		ft_mandelbrot(t_vars *var, int img_x, int img_y);
void		julia_pixel(t_vars *var, int img_x, int img_y);
int			iter_calcul(t_vector coordinate, t_vector c);
int			burning_ship(t_vector coordinate, t_vector c);

int			fract_color(const int idx);
int			fract_color_2(const int idx);
int			fract_color_3(const int idx);
void		draw_pixel(t_vars *var, int idx, int a, int b);
void		iterate_image(t_vars *var);

#endif
