/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_raycast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alubrano <alubrano@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 14:02:41 by alubrano          #+#    #+#             */
/*   Updated: 2026/05/04 14:45:25 by alubrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ray_left(t_game *game, t_ray *ray);
static void	ray_right(t_game *game, t_ray *ray);
static void	ray_up(t_game *game, t_ray *ray);
static void	ray_down(t_game *game, t_ray *ray);

/* Initializes ray parameters for a given screen column */
/* Computes ray direction, initial distances, and DDA step values. */
void	ft_init_ray(t_game *game, t_ray *ray, int x)
{
	double	cam;

	cam = 2.0 * x / WIN_W - 1.0;
	ray->ray_dir_x = game->player.dir_x + game->player.plane_x * cam;
	ray->ray_dir_y = game->player.dir_y + game->player.plane_y * cam;
	ray->map_x = (int)game->player.pos_x;
	ray->map_y = (int)game->player.pos_y;
	if (ray->ray_dir_x == 0)
		ray->delta_dist_x = 1e30; /* Infinite value: ray never crosses a vertical line */
	else
		ray->delta_dist_x = fabs(1.0 / ray->ray_dir_x);
	if (ray->ray_dir_y == 0)
		ray->delta_dist_y = 1e30; /* Infinite value: ray never crosses a horizontal line */
	else
		ray->delta_dist_y = fabs(1.0 / ray->ray_dir_y);
	if (ray->ray_dir_x < 0)
		ray_left(game, ray);
	else
		ray_right(game, ray);
	if (ray->ray_dir_y < 0)
		ray_up(game, ray);
	else
		ray_down(game, ray);
}

/* Initializes parameters for a ray going left */
static void	ray_left(t_game *game, t_ray *ray)
{
	ray->step_x = -1;
	ray->side_dist_x = (game->player.pos_x - ray->map_x)
		* ray->delta_dist_x;
}

/* Initializes parameters for a ray going right */
static void	ray_right(t_game *game, t_ray *ray)
{
	ray->step_x = 1;
	ray->side_dist_x = (ray->map_x + 1.0 - game->player.pos_x)
		* ray->delta_dist_x;
}

/* Initializes parameters for a ray going up */
static void	ray_up(t_game *game, t_ray *ray)
{
	ray->step_y = -1;
	ray->side_dist_y = (game->player.pos_y - ray->map_y)
		* ray->delta_dist_y;
}

/* Initializes parameters for a ray going down */
static void	ray_down(t_game *game, t_ray *ray)
{
	ray->step_y = 1;
	ray->side_dist_y = (ray->map_y + 1.0 - game->player.pos_y)
		* ray->delta_dist_y;
}
