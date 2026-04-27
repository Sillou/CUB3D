/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alubrano <alubrano@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 13:12:18 by alubrano          #+#    #+#             */
/*   Updated: 2026/04/27 14:15:23 by alubrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D
# define CUB3D

# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <libft.h>

/************************************/
/*				MSG_ERROR			*/
/************************************/

# define WG_INPUT1 "Too may args Ex : ./cub3d ./path_to_the_map/map.cub"
# define WG_INPUT2 "Map missing Ex : ./cub3d ./path_to_the_map/map.cub"
# define WG_INPUT3 "Wrong extention Ex : ./cub3d ./path_to_the_map/map.cub"

/************************************/
/*				MACROS				*/
/************************************/




/************************************/
/*				STRUCT				*/
/************************************/

typedef struct s_game
{
 
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
void	check_map(int argc, char **argv, t_game *game);


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
void	ft_error(char *error, t_game *game);
void	ft_clean(t_game *game);



#endif