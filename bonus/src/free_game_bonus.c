/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgagliar <kgagliar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 14:56:30 by kgagliar          #+#    #+#             */
/*   Updated: 2025/09/07 14:56:30 by kgagliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus/inc/so_long_bonus.h"

static void	free_tiles(t_game *game)
{
	if (game->img.empty)
		mlx_destroy_image(game->mlx, game->img.empty);
	if (game->img.wall)
		mlx_destroy_image(game->mlx, game->img.wall);
	if (game->img.collectible)
		mlx_destroy_image(game->mlx, game->img.collectible);
}

static void	free_exit(t_game *game)
{
	if (game->img.exit)
		mlx_destroy_image(game->mlx, game->img.exit);
	if (game->img.exit_closed)
		mlx_destroy_image(game->mlx, game->img.exit_closed);
}

static void	free_player(t_game *game)
{
	if (game->img.player_up1)
		mlx_destroy_image(game->mlx, game->img.player_up1);
	if (game->img.player_up2)
		mlx_destroy_image(game->mlx, game->img.player_up2);
	if (game->img.player_down1)
		mlx_destroy_image(game->mlx, game->img.player_down1);
	if (game->img.player_down2)
		mlx_destroy_image(game->mlx, game->img.player_down2);
	if (game->img.player_left1)
		mlx_destroy_image(game->mlx, game->img.player_left1);
	if (game->img.player_left2)
		mlx_destroy_image(game->mlx, game->img.player_left2);
	if (game->img.player_right1)
		mlx_destroy_image(game->mlx, game->img.player_right1);
	if (game->img.player_right2)
		mlx_destroy_image(game->mlx, game->img.player_right2);
}

static void	free_enemies(t_game *game)
{
	int	i;

	if (!game->enemies)
		return ;
	i = 0;
	while (i < game->enemy_count)
	{
		if (game->enemies[i].up1)
			mlx_destroy_image(game->mlx, game->enemies[i].up1);
		if (game->enemies[i].up2)
			mlx_destroy_image(game->mlx, game->enemies[i].up2);
		if (game->enemies[i].down1)
			mlx_destroy_image(game->mlx, game->enemies[i].down1);
		if (game->enemies[i].down2)
			mlx_destroy_image(game->mlx, game->enemies[i].down2);
		i++;
	}
	free(game->enemies);
}

void	free_images(t_game *game)
{
	free_tiles(game);
	free_exit(game);
	free_player(game);
	free_enemies(game);
}
