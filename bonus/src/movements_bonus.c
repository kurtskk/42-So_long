/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgagliar <kgagliar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 14:55:57 by kgagliar          #+#    #+#             */
/*   Updated: 2025/09/07 14:55:57 by kgagliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus/inc/so_long_bonus.h"

static int	is_enemy_at(t_game *game, int x, int y)
{
	int	i;

	i = 0;
	while (i < game->enemy_count)
	{
		if (game->enemies[i].x == x && game->enemies[i].y == y)
			return (1);
		i++;
	}
	return (0);
}

static void	handle_collectible(t_game *game, int x, int y)
{
	game->collected++;
	game->map[y][x] = '0';
}

static int	handle_exit(t_game *game)
{
	if (game->collected < game->c)
		return (0);
	close_game(game);
	return (1);
}

static void	move_player_on_map(t_game *game, int new_x, int new_y)
{
	if (game->map[game->y][game->x] != 'E')
		game->map[game->y][game->x] = '0';
	game->x = new_x;
	game->y = new_y;
	game->moves++;
	draw_map(game);
	display_moves(game);
	print_moves(game);
}

void	update_position(t_game *game, int new_x, int new_y)
{
	char	target;

	target = game->map[new_y][new_x];
	if (target == '1')
		return ;
	if (is_enemy_at(game, new_x, new_y))
		close_game(game);
	if (target == 'C')
		handle_collectible(game, new_x, new_y);
	if (target == 'E')
		if (!handle_exit(game))
			return ;
	move_player_on_map(game, new_x, new_y);
}
