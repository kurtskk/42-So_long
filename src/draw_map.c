/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgagliar <kgagliar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 15:46:52 by kgagliar          #+#    #+#             */
/*   Updated: 2025/09/07 15:46:52 by kgagliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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
}
