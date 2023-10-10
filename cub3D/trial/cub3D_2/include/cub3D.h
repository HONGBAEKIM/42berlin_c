/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:44:35 by hongbaki          #+#    #+#             */
/*   Updated: 2023/09/29 09:20:12 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* # define ERR_FILE			    "ERR_FILE"
# define ERR_FILE_EXTENSION	    "ERR_FILE_EXTENSION"
# define ERR_FD				    "ERR_FD"
# define ERR_INIT			    "ERR_INIT"
# define ERR_MAP_INIT		    "ERR_MAP_INIT" */

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
#define mapWidth 6
#define mapHeight 6
#define WALL 1
#define EMPTY 0
#define PLAYER 'N'
#define PI 3.1415926535
/* #define pos_x0 150
#define pos_y0 210
#define pos_ang 0.0 */



typedef struct s_data
{
	// 	char			player_char;
	int32_t		screen_width;
	int32_t		screen_height;
	// int				map_x;
	// int				map_y;
	// int				side;
	// int				line_height;
	// int				draw_start;
	// int				draw_end;
	// int				step_x;
	// int				step_y;
	// int				tex_x;
	// int				tex_y;
	// int				tex_num;
	// int				tex_width;
	// int				tex_height;
	double			pos_x0;
	double			pos_y0;
	double			pos_x1;
	double			pos_y1;
	double			pos_ang;
	// double			plane_x;
	// double			plane_y;
	double			camera_x;
	// double			raydir_x;
	// double			raydir_y;
	// double			side_dist_x;
	// double			side_dist_y;
	// double			delta_dist_x;
	// double			delta_dist_y;
	// double			perp_wall_dist;
	// double			tex_pos;
	// double			wall_x;
	// double			step;
}	t_data;

typedef struct s_cub
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_data		data;
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

// static void set_data(t_cub *cub);

//hook
//static void ft_hook(void* param);

//image
void clear_image(mlx_image_t *img, int32_t width, int32_t height, int32_t bg_color);
void mlx_fill_square(mlx_image_t *img, int x, int y, int size, int color);

//map
void displayMap(t_cub *cub);

//drwaline
void draw_line(mlx_image_t *img, int x0, int y0, int x1, int y1, int color);






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