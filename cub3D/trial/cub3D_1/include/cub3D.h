/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:44:35 by hongbaki          #+#    #+#             */
/*   Updated: 2023/09/28 16:13:50 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

//# define ERR_AC			    	"ERR_ARGC"
# define ERR_FILE			    "ERR_FILE"
# define ERR_FILE_EXTENSION	    "ERR_FILE_EXTENSION"
# define ERR_FD				    "ERR_FD"
# define ERR_INIT			    "ERR_INIT"
# define ERR_MAP_INIT		    "ERR_MAP_INIT"

# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h> //sin and cos

# include <fcntl.h>
# include <errno.h>
# include <MLX42.h>
# include <libft.h>
# include <get_next_line.h>



typedef enum e_colors
{
	BLACK	= 0x000000FF,
	WHITE	= 0xFFFFFFFF,
	RED		= 0xFF000088,
	GREEN	= 0x00FF0088,
	BLUE	= 0x0000FF88,
	SILVER	= 0xC0C0C0FF
}	t_colors;


#define WIDTH 2240
#define HEIGHT 1260

#define MAPWIDTH 6
#define MAPHEIGHT 6
#define WALL 1
#define EMPTY 0
#define PLAYER 'N'
#define PI 3.1415926535

#define NO_TEXTURE 10
#define SO_TEXTURE 20
#define WE_TEXTURE 30
#define EA_TEXTURE 40
#define F_TEXTURE 50


//pos_x0, y0 : start position
//pos_x1 = cos(pos_angle) * 5
//pos_y1 = cos(pos_angle) * 5



typedef struct s_data
{
	//move player
	double			pos_x0;
	double			pos_y0;
	double			pos_x1;
	double			pos_y1;
	double			pos_ang;	

	

	double			raydir_x;
	double			raydir_y;
	double			camera_x;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			delta_dist_x;
	double			delta_dist_y;

	//double			wall_x;
	double			side_dist_x;
	double			side_dist_y;
	
	double			perp_wall_dist;
	// 	char			player_char;
	// int32_t		screen_width;
	// int32_t		screen_height;
	int				map_pos_x;
	int				map_pos_y;
	int				step_x;
	int				step_y;

	
	// int				map_x;
	// int				map_y;


	// int				tex_x;
	// int				tex_y;
	// int				tex_num;
	// int				tex_width;
	// int				tex_height;

	// double			plane_x;
	// double			plane_y;
	//double			camera_x;
	

	
	// double			tex_pos;

	// double			step;
}	t_data;

typedef struct s_map 
{
	int		nrows;
	int		ncols;
	char	**data_c;
	int		**data_i;
	bool	c_alloc;
	bool	i_alloc;
}	t_map;

typedef struct s_cub
{
	t_map		map;
	t_data		data;
	mlx_t		*mlx;
	mlx_image_t	*img;
	mlx_texture_t	*textures[4];


	
	int				side;
	int				line_height;
	int				pitch;
	int				draw_start;
	int				draw_end;
	int				wall_direction;
	
	uint32_t		ceiling_color;
	uint32_t		floor_color;
	//void	*win;
	//t_map		*map;
	// uint32_t	rgb;
	// uint32_t	line_rgb;
	// int			bits_per_pixel;
	// int			line_length;
	// int			endian;
	// char		*addr;
}				t_cub;

//init
t_cub	*cub_init(int32_t width, int32_t height, char *name);

//raycast
void	calc_ray_dir(t_data *data, int x);
void	calc_delta_dist(t_data *data);
void	raycast(void *param);
void	calc_step_and_side_dist(t_cub *cub);
void	handle_wall_hit(t_cub *cub, int side);
void	perform_dda(t_cub *cub);

//move
void move(t_cub *cub);

//rotate
void rotate_left(t_cub *cub);
void rotate_right(t_cub *cub);

//image
void clear_image(mlx_image_t *img, int32_t width, int32_t height, int32_t bg_color);
void mlx_fill_square(mlx_image_t *img, int x, int y, int size, int color);

//map
void displayMap(t_cub *cub);

//drwaline
void draw_line(mlx_image_t *img, int x0, int y0, int x1, int y1);
//void draw_line(mlx_image_t *img, t_cub *cub);

//draw_texture
void	draw_floor_ceiling(t_cub *cub, int x);
void	draw_texture(t_cub *cub, int x);
void	draw_texture2(t_cub *cub, int x);
void	draw_texture3(t_cub *cub, int x, int tex_x);

//error msg
void	error_msg(char *msg);

//file_valid
static bool	cub_extension(char *cub_file);


//free
void ft_free_array(char **str);

/* typedef struct s_linehelper
{
	int	dx;
	int	sx;
	int	dy;
	int	sy;
	int	err;
	int	err2;
	int	x;
	int	y;
}			t_linehelper; */


/* typedef struct s_point
{
	float			height;
	unsigned int	color;
	struct s_point	*next;
	struct s_point	*last;
}					t_point; */

/* typedef struct s_coord
{
	int	x;
	int	y;
}				t_coord;  */

/* typedef struct mlx_key_data
{
	keys_t		key;
	action_t	action;
	int32_t		os_key;
	modifier_key_t	modifier;
}	mlx_key_data_t; */

/* typedef struct s_map
{
	int	width;
	int	height;
	int	**grid;
}			t_map; */

/* typedef struct s_map
{
	float	x_start;
	float	y_start;
	float	spacing;
	int		cols;
	int		rows;
	float	highest;
	float	lowest;
	t_point	*point;
}			t_map;  */






/* 
Example of color blue 
0x0000FF88
---------------------------------
0x  00  00    FF    88
    Red
        green
              blue
                    alpha(opacity)
 */

/* typedef struct s_map
{
    float	x_start;
	float	y_start;
	float	spacing;
	int		cols;
	int		rows;
	float	highest;
	float	lowest;
	t_point	*point;
}               t_map;

typedef struct s_fdf
{
    t_map   *map;
}               t_fdf; */

/* typedef struct s_coord
{
    int x;
    int y;
}               t_coord; */

#endif