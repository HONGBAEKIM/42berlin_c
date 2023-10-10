/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:44:35 by hongbaki          #+#    #+#             */
/*   Updated: 2023/10/10 15:50:07 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include <stdbool.h>
# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"

# define WIN_WIDTH 1200
# define WIN_HEIGHT 800
# define SQRS_PER_SEC 2.0 //squares (movement in a grid-based game)
# define RADS_PER_SEC 3.0 //radians (angular measurement )
# define NUM_TEXTURES 4

# define ERR_ARGS "Wrong number of arguments to program\n"
# define ERR_FILETYPE "Wrong file extension (should be .cub)\n"
# define ERR_FILE "File not found\n"
# define ERR_TEX_PATH "Invalid file format: Invalid texture file path\n"
# define ERR_READ "Could not read from file or unexpectedly reached end\n"
# define ERR_MLX_WIN "Could not create MLX window\n"
# define ERR_MLX_IMG "Could not create MLX image\n"
# define ERR_MLX_IMGWIN "Could not put image to window\n"
# define ERR_MAP_WALLS "Map is not completely surrouned by walls\n"
# define ERR_MEM_ROW "Memory allocation error for row\n"
# define ERR_MEM_ROWPTR "Memory allocation error for row pointers\n"
# define ERR_COL_VAL "Invalid file format: Invalid color value\n"
# define ERR_DUPL_TEX "Invalid file format: Duplicate texture path in file\n"
# define ERR_DUPL_COL "Invalid file format: Duplicate color path in file\n"
# define ERR_PREFIXES "Invalid file format: Prefix not NO, SO, WE, EA, F or C\n"
# define ERR_INVALID_MAP_CHAR "Invalid file format: Invalid character in map\n"
# define ERR_NO_PLAYPOS "Invalid file format: No player position\n"
# define ERR_DUP_PLAYPOS "Invalid file format: Duplicate player position\n"

typedef struct s_map 
{
	int		nrows;
	int		ncols;
	int		longest_ncols;
	char	**data_c;
	int		**data_i;
	bool	i_alloc;
	bool	c_alloc;
}	t_map;

typedef struct s_fileflags 
{
	bool	no;
	bool	so;
	bool	we;
	bool	ea;
	bool	f;
	bool	c;
}	t_fileflags;

typedef struct s_point2Dd 
{
	double	x;
	double	y;
}	t_pt2d_d;

typedef struct s_point2Di 
{
	int	x;
	int	y;
}	t_pt2d_i;

typedef struct cub_main 
{
	char			*filename;
	int				fd;
	char			char_read;
	char			map_char;
	int				total_chars_read;
	t_fileflags		fileflags;
	char			*tex_paths[4];
	bool			tex_paths_alloc;
	t_map			map;
	mlx_t			*mlx;
	mlx_image_t		*img;
	mlx_texture_t	*textures[4];
	bool			texture_alloc;
	t_pt2d_d		pos; //player's position
	t_pt2d_d		dir; // player's direction (the player is looking)
	t_pt2d_d		plane; // plane vectors (the plane of the screen)
	t_pt2d_d		raydr; // direction where Ray will be cast 
	t_pt2d_d		side_dist;
	//keep track of the distance the ray has traveled from 
	//its starting point to the first intersection with a grid cell or object boundary. 
	t_pt2d_d		delta_dist; 
	// determine how far the ray needs to move in the x and y directions between each step
	t_pt2d_i		map_pos; //map position
	t_pt2d_i		step; 
	t_pt2d_i		tex; 
	int				draw_start;
	int				draw_end;
	double			move_speed;
	double			rot_speed;
	int				side;
	int				wall_direction;
	double			perp_wall_dist;
	int				line_height;
	int				pitch;
	bool			key_w_pressed;
	bool			key_s_pressed;
	bool			key_d_pressed;
	bool			key_a_pressed;
	bool			key_left_pressed;
	bool			key_right_pressed;	
	uint32_t		ceiling_color;
	uint32_t		floor_color;
}	cub_main;

//01_check_map
void		check_map_command(int argc, char **argv);
int			ft_surround_check(cub_main *cub);

//02_print_map
void		print_map_c(t_map *map);
void		print_map_i(t_map *map);
void		print_cub_file_summary(cub_main *cub);

//03_init_cub
void	init_cub(int argc, char **argv, cub_main *cub);
void		init_fileflags(cub_main *cub);

//03_init_window
void	init_window(cub_main *cub);

//04_read
void	load_textures(cub_main *cub);
void	read_subject_file(char **argv, cub_main *cub);

//04_readcolor
bool		read_color_prefix(cub_main *cub, char *path);

//04_readmap_0
void		get_player_position(cub_main *cub);

//04_readmap_1
void		get_map_dims(cub_main *cub);
void		fill_map(cub_main *cub);

//04_readmap_2
void		malloc_map_i(cub_main *cub);
void		convert_map_data_c_to_i(cub_main *cub);

//04_readtexture
bool		read_tex_prefix(cub_main *cub, char *path);

//04_readutil
void		read_char(cub_main *cub);
bool		match_char(cub_main *cub, char char_to_match);
bool		*choose_fileflag(cub_main *cub, char *path);
void		read_prefixes(cub_main *cub);

//05_key
void	keyhook(mlx_key_data_t keydata, void *param);

//06_raycast
void		ft_raycast(void *param);

//07_move_wsad
void		move_player(cub_main *cub);

//07_move_rotate
void		rotate_left(cub_main *cub);
void		rotate_right(cub_main *cub);

//09_image
void	clear_image(cub_main *cub);

//10_math
t_pt2d_d	calc_ray_dir(int x, t_pt2d_d raydr, t_pt2d_d dir, t_pt2d_d plane);
t_pt2d_d	calc_delta_dist(t_pt2d_d delta_dist, t_pt2d_d raydr);
void		calc_step_and_side_dist(cub_main *cub);
void		perform_dda(cub_main *cub);

//11_draw
void		draw_tex(cub_main *cub, int x);

//end_0
void		ft_error(char *str, cub_main *cub);
void		delete_textures(cub_main *cub);
void		closehook(void *param);

//end_1
void		free_cub(cub_main *cub);

#endif