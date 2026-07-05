/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgagliar <kgagliar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 14:56:54 by kgagliar          #+#    #+#             */
/*   Updated: 2025/09/07 14:56:54 by kgagliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus/inc/so_long_bonus.h"

static void	aux_draw(t_game *game, int y, int x)
{
	void	*img;
	char	c;

	c = game->map[y][x];
	if (c == '1')
		img = game->img.wall;
	else if (c == 'C')
		img = game->img.collectible;
	else if (c == 'E')
	{
		if (game->collected < game->c)
			img = game->img.exit_closed;
		else
			img = game->img.exit;
	}
	else if (y == game->y && x == game->x)
		img = dir_player(game);
	else
		img = game->img.empty;
	mlx_put_image_to_window(game->mlx, game->win, img, x * TILE, y * TILE);
}

static void	draw_enemies(t_game *game)
{
	int		i;
	void	*img;

	i = 0;
	while (i < game->enemy_count)
	{
		if (game->enemies[i].dir == 1)
		{
			if (game->enemies[i].frame == 0)
				img = game->enemies[i].down1;
			else
				img = game->enemies[i].down2;
		}
		else
		{
			if (game->enemies[i].frame == 0)
				img = game->enemies[i].up1;
			else
				img = game->enemies[i].up2;
		}
		mlx_put_image_to_window(game->mlx, game->win,
			img, game->enemies[i].x * TILE, game->enemies[i].y * TILE);
		i++;
	}
}

void	draw_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			aux_draw(game, y, x);
			x++;
		}
		y++;
	}
	draw_enemies(game);
}
