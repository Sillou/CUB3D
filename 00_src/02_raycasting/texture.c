/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alubrano <alubrano@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 22:50:00 by alubrano          #+#    #+#             */
/*   Updated: 2026/05/04 22:58:01 by alubrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Place un pixel de couleur à la position (x, y) dans l'image principale
// Cette fonction écrit la couleur dans le buffer d'image à la position donnée.
void	ft_put_pixel(t_game *game, int x, int y, unsigned int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= WIN_W || y >= WIN_H)
		return ;
	dst = game->mlx.addr + (y * game->mlx.line_length)
		+ (x * (game->mlx.bpp / 8));
	*(unsigned int *)dst = color;
}

// Récupère la couleur d'un pixel (tex_x, tex_y) dans une texture
// Cette fonction lit la couleur du pixel dans la texture à la position donnée.
unsigned int	get_texture_color(t_tex *tex, int tex_x, int tex_y)
{
	char	*pixel;

	if (tex_x < 0 || tex_x >= tex->width || tex_y < 0 || tex_y >= tex->height)
		return (0);
	pixel = tex->addr + (tex_y * tex->line_length)
		+ (tex_x * (tex->bpp / 8));
	return (*(unsigned int *)pixel);
}

// Retourne la texture à utiliser selon la direction du mur touché
// Cette fonction choisit la texture murale selon la direction du rayon.
t_tex	*get_wall_texture(t_game *game, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->step_x > 0)
			return (&game->textures.ea);
		else
			return (&game->textures.we);
	}
	else
	{
		if (ray->step_y > 0)
			return (&game->textures.so);
		else
			return (&game->textures.no);
	}
}

// Calcule la coordonnée X sur la texture à partir de la position du mur touché
// Cette fonction calcule la position horizontale sur la texture à partir de l'impact du rayon.
int	get_tex_x(t_game *game, t_ray *ray, t_tex *tex)
{
	double	wall_x;
	int		tex_x;

	if (ray->side == 0)
		wall_x = game->player.pos_y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		wall_x = game->player.pos_x + ray->perp_wall_dist * ray->ray_dir_x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (double)tex->width);
	if ((ray->side == 0 && ray->ray_dir_x > 0)
		|| (ray->side == 1 && ray->ray_dir_y < 0))
		tex_x = tex->width - tex_x - 1;
	return (tex_x);
}
