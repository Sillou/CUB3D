/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alubrano <alubrano@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 13:12:18 by alubrano          #+#    #+#             */
/*   Updated: 2026/04/28 16:39:48 by alubrano         ###   ########.fr       */
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

// typedef struct s_map
// {
// 	tableau de la Map
// 	largeur
// 	longeur
// }	t_map;

// typedef struct s_config
// {
// 	chemin des textures
// 	couleur floor/ ceiling
// }	t_config;

// typedef struct s_player
// {
// 	int		x;
// 	int		y;
// 	direction initiale
// 	angle ou vecteur directionels
// }	t_player;

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
	// t_map		map;
	// t_config	config;
	// t_player	player;
	// t_mlx		mlx;
	// t_tex		tex;
	int	test;

}	t_game;


/************************************/
/*				MAIN				*/
/************************************/

/*main.c*/
int	main(int argc, char **argv);


/************************************/
/*				PARSING				*/
/************************************/

/*validation.c*/
void	check_args(int argc, char **argv, t_game *game);


/************************************/
/*				INIT				*/
/************************************/


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
void	msg_error(char *str, char *error_msg, t_game *game);
void	ft_clean(t_game *game);



#endif
