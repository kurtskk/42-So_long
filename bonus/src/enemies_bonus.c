/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgagliar <kgagliar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 14:56:47 by kgagliar          #+#    #+#             */
/*   Updated: 2025/09/07 14:56:47 by kgagliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus/inc/so_long_bonus.h"

static int	count_enemies(char **map, int height, int width)
{
	int	y;
	int	x;
	int	count;

	count = 0;
	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			if (map[y][x] == 'M')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

static void	fill_enemies(t_game *game)
{
	int	y;
	int	x;
	int	i;

	i = 0;
	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == 'M')
			{
				game->enemies[i].x = x;
				game->enemies[i].y = y;
				game->enemies[i].dir = 1;
				game->enemies[i].frame = 0;
				i++;
			}
			x++;
		}
		y++;
	}
}

void	init_enemy_pos(t_game *game)
{
	game->enemy_count = count_enemies(game->map, game->height, game->width);
	if (game->enemy_count == 0)
		return ;
	game->enemies = malloc(sizeof(t_enemy) * game->enemy_count);
	if (!game->enemies)
		error_exit("Error: failed to allocate enemies");
	fill_enemies(game);
}
