/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgagliar <kgagliar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 14:55:48 by kgagliar          #+#    #+#             */
/*   Updated: 2025/09/07 14:55:48 by kgagliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus/inc/so_long_bonus.h"

int	move_up(t_game *game)
{
	game->player_dir = DIR_UP;
	update_position(game, game->x, game->y - 1);
	return (1);
}

int	move_down(t_game *game)
{
	game->player_dir = DIR_DOWN;
	update_position(game, game->x, game->y + 1);
	return (1);
}

int	move_left(t_game *game)
{
	game->player_dir = DIR_LEFT;
	update_position(game, game->x - 1, game->y);
	return (1);
}

int	move_right(t_game *game)
{
	game->player_dir = DIR_RIGHT;
	update_position(game, game->x + 1, game->y);
	return (1);
}
