/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_image_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgagliar <kgagliar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 14:56:38 by kgagliar          #+#    #+#             */
/*   Updated: 2025/09/07 14:56:38 by kgagliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus/inc/so_long_bonus.h"

static void	file_to_image_player(t_game *game)
{
	int	a;

	a = IMG_PXL;
	game->img.player_right1 = mlx_xpm_file_to_image(game->mlx,
			"assets/sprites/2B/right-1.xpm", &a, &a);
	game->img.player_right2 = mlx_xpm_file_to_image(game->mlx,
			"assets/sprites/2B/right-2.xpm", &a, &a);
	game->img.player_up1 = mlx_xpm_file_to_image(game->mlx,
			"assets/sprites/2B/up-1.xpm", &a, &a);
	game->img.player_up2 = mlx_xpm_file_to_image(game->mlx,
			"assets/sprites/2B/up-2.xpm", &a, &a);
	game->img.player_down1 = mlx_xpm_file_to_image(game->mlx,
			"assets/sprites/2B/down-1.xpm", &a, &a);
	game->img.player_down2 = mlx_xpm_file_to_image(game->mlx,
			"assets/sprites/2B/down-2.xpm", &a, &a);
	game->img.player_left1 = mlx_xpm_file_to_image(game->mlx,
			"assets/sprites/2B/left-1.xpm", &a, &a);
	game->img.player_left2 = mlx_xpm_file_to_image(game->mlx,
			"assets/sprites/2B/left-2.xpm", &a, &a);
}

static void	file_to_enemy(t_game *game)
{
	int	i;
	int	a;

	if (game->enemy_count == 0)
		return ;
	a = IMG_PXL;
	i = 0;
	while (i < game->enemy_count)
	{
		game->enemies[i].up1 = mlx_xpm_file_to_image(game->mlx,
				"assets/sprites/Emil/Emil_up1.xpm", &a, &a);
		game->enemies[i].up2 = mlx_xpm_file_to_image(game->mlx,
				"assets/sprites/Emil/Emil_up2.xpm", &a, &a);
		game->enemies[i].down1 = mlx_xpm_file_to_image(game->mlx,
				"assets/sprites/Emil/Emil_down1.xpm", &a, &a);
		game->enemies[i].down2 = mlx_xpm_file_to_image(game->mlx,
				"assets/sprites/Emil/Emil_down2.xpm", &a, &a);
		i++;
	}
}

void	file_to_image(t_game *game)
{
	int	a;

	a = IMG_PXL;
	game->img.empty = mlx_xpm_file_to_image(game->mlx,
			"assets/tiles/floor.xpm", &a, &a);
	game->img.wall = mlx_xpm_file_to_image(game->mlx,
			"assets/tiles/wall.xpm", &a, &a);
	game->img.exit_closed = mlx_xpm_file_to_image(game->mlx,
			"assets/images/9S_exit.xpm", &a, &a);
	game->img.exit = mlx_xpm_file_to_image(game->mlx,
			"assets/images/9S_exit1.xpm", &a, &a);
	game->img.collectible = mlx_xpm_file_to_image(game->mlx,
			"assets/images/pod_collectible.xpm", &a, &a);
	file_to_image_player(game);
	file_to_enemy(game);
}
