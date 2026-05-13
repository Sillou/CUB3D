/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alubrano <alubrano@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 22:50:00 by alubrano          #+#    #+#             */
/*   Updated: 2026/05/13 15:19:54 by alubrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* Places a colored pixel at position (x, y) in the main image buffer */
/* Writes the color into the image buffer at the given position. */
void	ft_put_pixel(t_game *game, int x, int y, unsigned int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= WIN_W || y >= WIN_H)
		return ;
	dst = game->mlx.addr + (y * game->mlx.line_length)
		+ (x * (game->mlx.bpp / 8));
	*(unsigned int *)dst = color;
}

/* Retrieves the color of pixel (tex_x, tex_y) from a texture */
/* Reads the pixel color from the texture at the given position. */
unsigned int	get_texture_color(t_tex *tex, int tex_x, int tex_y)
{
	char	*pixel;

	if (tex_x < 0 || tex_x >= tex->width || tex_y < 0 || tex_y >= tex->height)
		return (0);
	pixel = tex->addr + (tex_y * tex->line_length)
		+ (tex_x * (tex->bpp / 8));
	return (*(unsigned int *)pixel);
}

/* Chooses the wall texture according to the ray direction. */
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

/* Computes the X coordinate on the texture from the wall hit position */
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
