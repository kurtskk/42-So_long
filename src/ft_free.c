/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgagliar <kgagliar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 15:47:07 by kgagliar          #+#    #+#             */
/*   Updated: 2025/09/07 15:47:07 by kgagliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	free_player_images(t_game *game)
{
	if (game->img.player_left1)
		mlx_destroy_image(game->mlx, game->img.player_left1);
	if (game->img.player_left2)
		mlx_destroy_image(game->mlx, game->img.player_left2);
	if (game->img.player_right1)
		mlx_destroy_image(game->mlx, game->img.player_right1);
	if (game->img.player_right2)
		mlx_destroy_image(game->mlx, game->img.player_right2);
	if (game->img.player_up1)
		mlx_destroy_image(game->mlx, game->img.player_up1);
	if (game->img.player_up2)
		mlx_destroy_image(game->mlx, game->img.player_up2);
	if (game->img.player_down1)
		mlx_destroy_image(game->mlx, game->img.player_down1);
	if (game->img.player_down2)
		mlx_destroy_image(game->mlx, game->img.player_down2);
}

void	free_images(t_game *game)
{
	if (game->img.wall)
		mlx_destroy_image(game->mlx, game->img.wall);
	if (game->img.empty)
		mlx_destroy_image(game->mlx, game->img.empty);
	if (game->img.collectible)
		mlx_destroy_image(game->mlx, game->img.collectible);
	if (game->img.exit)
		mlx_destroy_image(game->mlx, game->img.exit);
	if (game->img.exit_closed)
		mlx_destroy_image(game->mlx, game->img.exit_closed);
	free_player_images(game);
}
