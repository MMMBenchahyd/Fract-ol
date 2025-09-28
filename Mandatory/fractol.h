/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenchah <mbenchah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 00:31:07 by mbenchah          #+#    #+#             */
/*   Updated: 2025/03/19 17:16:45 by mbenchah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h> 

# define MAX_ITER 200
# define WIDTH 800
# define HEIGHT 800

# define KEYCODE_ESC 53 
# define MOUSECODE_SCROLL_UP 5
# define MOUSECODE_SCROLL_DOWN 4

typedef struct s_mlx_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}				t_mlx_data;

typedef struct s_vector
{
	double	x;
	double	y;
}				t_vector;

typedef struct s_vars
{
	void			*mlx;
	void			*win;
	int				(*fract_color)(const int);
	void			(*fract_func)(struct s_vars *, int, int);
	int				(*iter_calcul)(t_vector, t_vector);
	t_vector		map_start;
	t_vector		map_end;
	t_mlx_data		*img;
	t_vector		julia_c;
}				t_vars;

void		pixel_color(t_mlx_data *data, int x, int y, unsigned int color);
double		ft_map(const int value, const int max, \
	const double fmin, const double fmax);

void		ft_exit(const int code, const t_vars *var);
void		ft_calc_zoom(t_vars *var, const double factor);
double		ft_atod(const char *s);
void		ft_set_map(t_vars *var);

int			ft_parsing(t_vars *var, int ac, char **av);
void		ft_putstr_fd(const int file_d, const char *s);
int			ft_strncmp(const char *s1, const char *s2, size_t n);

int			key_hook(int key, t_vars *var);
void		ft_write_str(const int file_d, const char *s);
int			destroy_hook(t_vars	*var);

void		draw_pixel(t_vars *var, int idx, int a, int b);
int			valid_double(char *s);
size_t		ft_strlen(const char *s);

void		iterate_image(t_vars *var);
void		ft_mandelbrot(t_vars *var, int img_x, int img_y);
void		julia_pixel(t_vars *var, int img_x, int img_y);

int			mouse_hook(int mouse_code, int a, int b, t_vars *var);
int			iter_calcul(t_vector coordinate, t_vector c);
int			fract_color(const int idx);

#endif
