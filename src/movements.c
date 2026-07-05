/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgagliar <kgagliar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 15:47:21 by kgagliar          #+#    #+#             */
/*   Updated: 2025/09/07 15:47:21 by kgagliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	update_position(t_game *game, int new_x, int new_y)
{
	char	target;

	target = game->map[new_y][new_x];
	if (target == '1')
		return ;
	if (target == 'C')
	{
		game->collected++;
		game->map[new_y][new_x] = '0';
	}
	if (target == 'E')
	{
		if (game->collected < game->c)
			return ;
		else
			close_game(game);
	}
	if (game->map[game->y][game->x] != 'E')
		game->map[game->y][game->x] = '0';
	game->x = new_x;
	game->y = new_y;
	game->moves++;
	draw_map(game);
	print_moves(game);
}
