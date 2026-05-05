/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alubrano <alubrano@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 12:06:49 by alubrano          #+#    #+#             */
/*   Updated: 2026/05/04 22:58:01 by alubrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_draw_bg(t_game *game);
static void	ft_dda(t_game *game, t_ray *ray);
static void	draw_textured_line(t_game *game, int x, t_ray *ray, t_tex *tex);
static void	ft_draw_column(t_game *game, int x, t_ray *ray);

// Lance le raycasting sur chaque colonne de l'écran et affiche le résultat
void	ft_raycast(t_game *game)
{
	t_ray	ray;
	int		x;

	ft_draw_bg(game);
	x = 0;
	while (x < WIN_W)
	{
		ft_init_ray(game, &ray, x);
		ft_dda(game, &ray);
		if (ray.side == 0)
			ray.perp_wall_dist = ray.side_dist_x - ray.delta_dist_x;
		else
			ray.perp_wall_dist = ray.side_dist_y - ray.delta_dist_y;
		ray.line_height = (int)(WIN_H / ray.perp_wall_dist);
		ray.draw_start = -ray.line_height / 2 + WIN_H / 2;
		if (ray.draw_start < 0)
			ray.draw_start = 0;
		ray.draw_end = ray.line_height / 2 + WIN_H / 2;
		if (ray.draw_end >= WIN_H)
			ray.draw_end = WIN_H - 1;
		ft_draw_column(game, x, &ray);
		x++;
	}
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->mlx.img, 0, 0);
}

// Remplit l'arrière-plan avec la couleur du plafond et du sol
static void	ft_draw_bg(t_game *game)
{
	unsigned int	ceil_c;
	unsigned int	floor_c;
	int				x;
	int				y;

	ceil_c = (game->config.ceiling.r << 16)
		| (game->config.ceiling.g << 8) | game->config.ceiling.b;
	floor_c = (game->config.floor.r << 16)
		| (game->config.floor.g << 8) | game->config.floor.b;
	y = 0;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			if (y < WIN_H / 2)
				ft_put_pixel(game, x, y, ceil_c);
			else
				ft_put_pixel(game, x, y, floor_c);
			x++;
		}
		y++;
	}
}

// Algorithme DDA pour trouver le mur touché par le rayon
static void	ft_dda(t_game *game, t_ray *ray)
{
	while (game->map.full[ray->map_y][ray->map_x] != '1')
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
	}
}

// Dessine une colonne texturée à l'écran à la position x
static void	draw_textured_line(t_game *game, int x, t_ray *ray, t_tex *tex)
{
	int		tex_x;
	int		tex_y;
	int		y;
	double	step;
	double	tex_pos;

	tex_x = get_tex_x(game, ray, tex);
	step = 1.0 * tex->height / ray->line_height;
	tex_pos = (ray->draw_start - WIN_H / 2 + ray->line_height / 2) * step;
	y = ray->draw_start;
	while (y <= ray->draw_end)
	{
		tex_y = (int)tex_pos & (tex->height - 1);
		tex_pos += step;
		ft_put_pixel(game, x, y, get_texture_color(tex, tex_x, tex_y));
		y++;
	}
}

// Sélectionne la bonne texture et dessine la colonne correspondante
static void	ft_draw_column(t_game *game, int x, t_ray *ray)
{
	t_tex	*tex;

	tex = get_wall_texture(game, ray);
	draw_textured_line(game, x, ray, tex);
}
