/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hongbaki <hongbaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:44:35 by hongbaki          #+#    #+#             */
/*   Updated: 2023/09/11 15:57:25 by hongbaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define ERR_FILE			    "ERR_FILE"
# define ERR_FILE_EXTENSION	    "ERR_FILE_EXTENSION"
# define ERR_FD				    "ERR_FD"
# define ERR_INIT			    "ERR_INIT"
# define ERR_MAP_INIT		    "ERR_MAP_INIT"

# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <MLX42.h>
# include <libft.h>
# include <get_next_line.h>

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

typedef enum e_colors
{
	BLACK	= 0x000000FF,
	WHITE	= 0xFFFFFFFF,
	RED		= 0xFF000088,
	GREEN	= 0x00FF0088,
	BLUE	= 0x0000FF88,
	SILVER	= 0xC0C0C0FF
}	t_colors;

# ifndef WIDTH
#  define WIDTH 2240
# endif
# ifndef HEIGHT
#  define HEIGHT 1260
# endif

typedef struct s_linehelper
{
	int	dx;
	int	sx;
	int	dy;
	int	sy;
	int	err;
	int	err2;
	int	x;
	int	y;
}			t_linehelper;

typedef struct s_point
{
	float			height;
	unsigned int	color;
	struct s_point	*next;
	struct s_point	*last;
}					t_point;

typedef struct s_coord
{
	int	x;
	int	y;
}				t_coord;

/* typedef struct mlx_key_data
{
	keys_t		key;
	action_t	action;
	int32_t		os_key;
	modifier_key_t	modifier;
}	mlx_key_data_t; */

typedef struct s_map
{
	float	x_start;
	float	y_start;
	float	spacing;
	int		cols;
	int		rows;
	float	highest;
	float	lowest;
	t_point	*point;
}			t_map;

typedef struct s_fdf
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_map		*map;
	uint32_t	rgb;
	uint32_t	line_rgb;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	char		*addr;
}				t_fdf;

// t_fdf	*fdf_init(int32_t width, int32_t height, char *name);
// int		check_fdfnull(char *test_map, char *fdfnull);
// void	free_array(char **array);
// int		ft_isblank(char c);
// t_map	*parse(t_fdf *fdf, int fd);
// t_point	*pt_new(float height, unsigned int color);
// void	pt_add_back(t_point *dst, t_point *new);
// void	pt_clear(t_point *pt);
// t_point	*next_row_pt(t_point *pt, int cols);
// t_map	*map_new(void);
// void	translate(t_fdf *fdf, char xy, int amount);
// void	zoom(t_fdf *fdf, int amount);
// void	change_height(t_fdf *fdf, float factor, int up);
// void	change_color(t_fdf *fdf, uint32_t rgb);
// void	stop(char *s);
// void	lh_init(t_linehelper *lh, t_coord *c0, t_coord *c1);
// void	draw(t_fdf *fdf, t_map *map);

int	greenDotY = 200;
int	greenDotX = 200;


#endif