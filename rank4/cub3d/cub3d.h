/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhashir <mhashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:33:05 by mhashir          #+#    #+#             */
/*   Updated: 2025/07/28 04:22:12 by mhashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include "mlx/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 900
# define HEIGHT 500

# define NO 1
# define SO 2
# define WE 3
# define EA 4
# define FLOOR 0
# define CEILING 1

typedef struct s_player
{
	double		pos_x;
	double		pos_y;
	double		dir_y;
	double		dir_x;
	double		plane_x;
	double		plane_y;
}				t_player;

typedef struct s_map
{
	char		**map;
	char		*w_comp;
	char		*n_comp;
	char		*e_comp;
	char		*s_comp;
	char		*shade_of_floor;
	char		*shade_of_ceiling;
	int			composition_of_west;
	int			composition_of_north;
	int			composition_of_south;
	int			composition_of_east;
	int			ceil_r;
	int			ceil_g;
	int			ceil_b;
	int			floor_r;
	int			floor_g;
	int			floor_b;
	int			max;
	int			size;
	int			color_of_floor;
	int			color_of_ceiling;
	int			floor_gradient_start;
	int			floor_gradient_end;
	int			ceiling_gradient_start;
	int			ceiling_gradient_end;
}				t_map;

typedef struct s_img
{
	void		*img_ptr;
	int			*data;
	int			width;
	int			height;
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef struct s_ray
{
	double		camera_x;
	double		raydir_x;
	double		raydir_y;
	int			map_x;
	int			map_y;
	double		sidedist_x;
	double		sidedist_y;
	double		deltadist_x;
	double		deltadist_y;
	double		perp_wall_dist;
	int			step_x;
	int			step_y;
	int			side;
	double		wallx;
	int			tex_x;
	double		step;
}				t_ray;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	int			buf[HEIGHT][WIDTH];
	int			key_a;
	int			key_d;
	int			key_s;
	int			key_w;
	int			key_right;
	int			key_left;
	int			texture[4][4096];
	t_map		map;
	t_img		img[5];
	t_player	player;
	t_ray		ray;
}				t_mlx;

//set_player
void			initialize_ns_direction(t_mlx *mlx, int north);
void			initialize_we_direction(t_mlx *mlx, int west);
void			setup_player_orientation(t_mlx *mlx);
void			initialize_game_view(t_mlx *mlx);

//validate_map_structure
int				validate_map_structure(t_mlx *mlx);
int				analyze_map_spaces(t_mlx *mlx);
int				validate_top_bottom_walls(t_mlx *mlx);
int				validate_side_walls(t_mlx *mlx);
int				validate_starting_position(t_mlx *mlx);

//allocate_map_memory
int				copy_map_to_memory(t_mlx *mlx, char **strs, int max);
int				find_width(char **strs);
int				allocate_map_memory(t_mlx *mlx, char **strs);

//key_press
int				handle_key_release(int keycode, t_mlx *mlx);
int				cleanup_and_exit(t_mlx *mlx);
int				handle_key_press(int keycode, t_mlx *mlx);
void			rotate_player_clockwise(t_mlx *mlx);
void			rotate_player_counterclockwise(t_mlx *mlx);

//move_player
void			strafe_player_left(t_mlx *mlx);
void			strafe_player_right(t_mlx *mlx);
void			move_player_forward(t_mlx *mlx);
void			move_player_backward(t_mlx *mlx);

//utils
int				set_ceiling_color(t_mlx *mlx, char *str);
int				set_floor_color(t_mlx *mlx, char *str);

//vars_analysisis
int				parse_north_texture(t_mlx *mlx, char *str);
int				parse_south_texture(t_mlx *mlx, char *str);
int				parse_west_texture(t_mlx *mlx, char *str);
int				parse_east_texture(t_mlx *mlx, char *str);
int				validate_ceiling_and_floor(t_mlx *mlx, char *str);

//help_analysis
int				is_position_enclosed(char **map, int row, int colum);
int				analyze_map_enclosure(t_mlx *mlx);
int				check_horizontal_borders(t_mlx *mlx, int row, int colum);
int				check_vertical_borders(t_mlx *mlx, int row, int colum);
int				is_map_surrounded_by_walls(t_mlx *mlx, char **map, int i,
					int z);

//draw_vertical_line
int				get_color(t_mlx *mlx, int texy);
void			draw_column(t_mlx *mlx, int x, int assign_start,
					int assign_end);
int				rgb_to_hex(int r, int g, int b);
void			draw_vertical_line(t_mlx *mlx, int assign_start, int assign_end,
					int x);

//execute_frame_actions
void			init_raycast(t_mlx *mlx);
void			calculate_ray_steps(t_mlx *mlx);
void			dda_algorithm(t_mlx *mlx);
void			render_walls(t_mlx *mlx, int x);
void			setup_ray_parameters(t_mlx *mlx);
void			compute_ray_direction(t_mlx *mlx);
void			perform_ray_casting(t_mlx *mlx);
void			calculate_wall_dimensions(t_mlx *mlx, int x);

//start_game_loop
void			update_display(t_mlx *mlx);
void			handle_player_movement(t_mlx *mlx);
void			execute_frame_actions(t_mlx *mlx);
int				start_game_loop(t_mlx *mlx);

//main
void			initiate_structure(t_mlx *mlx);
void			keys_initiate(t_mlx *mlx);
int				load_and_process_map(t_mlx *mlx, char *file_name);
int				mlx_initiate(t_mlx *mlx);

//set_map
char			*strjoin_cube(char *s1, char *s2);
int				display_error(char *str, char *fd);
int				validate_map_file(char *filename);
char			**parse_map_file(char *filename);
int				validate_map_content(char *map);

//init_map
int				verify_map_format(t_mlx *mlx, char **strs);
int				check_map_elements_complete(t_mlx *mlx);
int				process_map_elements(t_mlx *mlx, char *str);
int				setup_map_configuration(t_mlx *mlx, char **strs, int i);

//map_config
int				is_valid_identifier(char *str);
int				process_map_textures(t_mlx *mlx, char *str);
int				process_map_colors(t_mlx *mlx, char *str);

//free
void			free_split(char **strs);
void			free_map(t_mlx *mlx);
void			free_game_resources(t_mlx *mlx);

//map_validity_check
int				check_bottom_column(t_mlx *mlx, char **strs);
int				check_top_column(t_mlx *mlx, char **strs);
int				validate_color_values(t_mlx *mlx);
int				map_validity_check(t_mlx *mlx);
int				check_valid_number(const char *str);

//parsing
int				check_cub_extension(char *filename);
int				parsing(t_mlx *mlx, char **strs);
int				is_map_valid(char *str);
int				analyze_newlines(char *map);
int				handle_newline(char *str);
#endif