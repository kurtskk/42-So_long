/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgagliar <kgagliar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 15:47:55 by kgagliar          #+#    #+#             */
/*   Updated: 2025/09/07 15:47:55 by kgagliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	*dir_player_up(t_game *game)
{
	if (game->player_frame == 0)
		return (game->img.player_up1);
	return (game->img.player_up2);
}

static void	*dir_player_down(t_game *game)
{
	if (game->player_frame == 0)
		return (game->img.player_down1);
	return (game->img.player_down2);
}

static void	*dir_player_left(t_game *game)
{
	if (game->player_frame == 0)
		return (game->img.player_left1);
	return (game->img.player_left2);
}

static void	*dir_player_right(t_game *game)
{
	if (game->player_frame == 0)
		return (game->img.player_right1);
	return (game->img.player_right2);
}

void	*dir_player(t_game *game)
{
	if (game->player_dir == DIR_UP)
		return (dir_player_up(game));
	if (game->player_dir == DIR_DOWN)
		return (dir_player_down(game));
	if (game->player_dir == DIR_LEFT)
		return (dir_player_left(game));
	if (game->player_dir == DIR_RIGHT)
		return (dir_player_right(game));
	return (game->img.player_down1);
}
