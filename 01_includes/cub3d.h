/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alubrano <alubrano@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 13:12:18 by alubrano          #+#    #+#             */
/*   Updated: 2026/04/29 15:18:25 by alubrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D
# define CUB3D

# include "mlx.h"
# include "libft.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>


/************************************/
/*				MSG_ERROR			*/
/************************************/

# define WG_INPUT1 "Too may args Ex : ./cub3d ./path_to_the_map/map.cub"
# define WG_INPUT2 "Map missing Ex : ./cub3d ./path_to_the_map/map.cub"
# define WG_INPUT3 "Wrong extention Ex : ./cub3d ./path_to_the_map/map.cub"
# define WG_FILE "Is a directory"


/************************************/
/*				MACROS				*/
/************************************/

# ifdef BONUS
#  define BONUS 1
# endif


/************************************/
/*				STRUCT				*/
/************************************/

typedef struct s_map
{
	char	**map;
	int		width;
	int		hight;
}	t_map;

typedef struct s_color
{
	int		r;
	int		g;
	int		b;
}	t_color;


typedef struct s_config
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	t_color	floor;
	t_color	ceiling;
	int		floor_set;
	int		ceiling_set;
}	t_config;

typedef struct s_player
{
	int		x;
	int		y;
	// direction initiale
	// angle ou vecteur directionels
}	t_player;

// typedef struct s_mlx
// {
// 	pointeur mlx
// 	fenetre
// 	image buffer
// }	t_mlx;

// typedef struct s_tex
// {
// 	texture chargees
// 	dimensions
// 	acces pixel
// }	t_tex;

// typedef struct s_ray
// {
// 	infos dun rayon pendant le rendu
// }	t_ray;


typedef struct s_game
{
	t_map		map;
	t_config	config;
	t_player	player;
	// t_mlx		mlx;
	// t_tex		tex;

}	t_game;


/************************************/
/*				MAIN				*/
/************************************/

/*main.c*/
int	main(int argc, char **argv);


/************************************/
/*				PARSING				*/
/************************************/

/*check_args.c*/
void	check_args(int argc, char **argv, t_game *game);

/*chech_map.c*/
void	check_map(char *argv, t_game *game);
void	add_map_line(char *line, t_game *game);


/*parse_map.c*/
int		parse_befor_map(char *line, t_game *game);

/*parse_texture.c*/
void	ft_texture(char *line, t_game *game);

/*parse_color.c*/
void	add_color(char *line, char str, t_game *game, int i);

/*pars_utils.c*/
int		ft_is_space(char line);
int		skip_spaces(char *line, int i);


/*check_valid_map.c*/
void	check_valid_map(t_game *game);

/*check_valid_map2.c*/
void	check_color_range(t_color color, char *name, t_game *game);
int		is_player(char c);


/************************************/
/*				INIT				*/
/************************************/

/*init_to_start.c*/
void	init_start(t_game *game);

/************************************/
/*				RAYCAST				*/
/************************************/


/************************************/
/*				MOVES				*/
/************************************/


/************************************/
/*				EXIT				*/
/************************************/

/*close.c*/
void	msg_error(char *str, char *error_msg, t_game *game, int code);
void	ft_clean(t_game *game);

/*free_mem.c*/
void	free_map(t_game *game);
void	free_config(t_game *game);


#endif
