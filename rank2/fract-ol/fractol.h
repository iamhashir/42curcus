/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhashir <mhashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 03:35:36 by mhashir           #+#    #+#             */
/*   Updated: 2024/07/06 04:10:10 by mhashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define ERROR_MESSAGE "Enter\t\" Julia 1 2\"\t or \t\" Mandelbrot\""

# define WIDTH 1000
# define HEIGHT 1000

# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF

# define NUDE_PINK 0xF2DADF
# define DARK_BLUE 0x0e1565

typedef struct s_complex
{
	long double	x;
	long double	y;
}				t_complex;

typedef struct s_img
{
	void		*img_ptr;
	char		*pixels_ptr;
	int			bpp;
	int			endian;
	int			fract_len;
	double		scale;
}				t_img;

typedef struct s_fractol
{
	char		*name;
	void		*mlx_connection;
	void		*mlx_window;
	t_img		img;
	double		esc_button;
	int			iterations_defintion;
	double		shift_posx;
	double		shift_posy;
	double		zoom;
	double		julia_posx;
	double		julia_posy;
	int			is_locked;
}				t_fractol;

typedef struct s_mappingrange
{
	double		n_min;
	double		n_max;
	double		o_min;
	double		o_max;
}				t_mappingrange;

int				ft_strncmp(char *str1, char *str2, unsigned int n);
void			ft_putstr_fd(char *s, int fd);
double			ft_atodbl(char *s);
double			map(double uns_num, t_mappingrange range);
int				key_handler(int keycode, t_fractol *fractol);
void			arrow_keys_parse(t_fractol *fractol, int keycode);
t_complex		sum_complex(t_complex z1, t_complex z2);
t_complex		mapped_parsing(int x, int y, t_fractol *fractal);
t_complex		square_complex(t_complex z);
int				ft_strlen(char *str);
int				julia_valid_check(const char *param);
void			fractal_init(t_fractol *fractal);
void			fractol_render(t_fractol *fractol);
int				julia_parse(t_fractol *fractal, char **av);
void			handle_key2(t_fractol *fractol, int keycode);
void			handle_key(t_fractol *fractol, int keycode);
int				julia_moves(int x, int y, t_fractol *fractal);
int				julia_parse(t_fractol *fractal, char **av);
int				handler_esc(t_fractol *fractol);
int				mouse_keyhook(int button, int x, int y, t_fractol *fractol);
int				get_color_pixel(t_complex z, t_complex c,
					t_fractol *fractal);
void			handle_pixel(int x, int y, t_fractol *fractal);

extern int		mouse_keyhook(int button, int x, int y, t_fractol *fractol);
extern int		handler_esc(t_fractol *fractal);
extern int		julia_moves(int x, int y, t_fractol *fractal);
extern int		key_handler(int keysym, t_fractol *fractal);

#endif