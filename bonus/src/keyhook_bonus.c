/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgagliar <kgagliar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 14:56:22 by kgagliar          #+#    #+#             */
/*   Updated: 2025/09/07 14:56:22 by kgagliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus/inc/so_long_bonus.h"

static void	switch_frame(t_game *game)
{
	if (game->player_frame == 0)
		game->player_frame = 1;
	else
		game->player_frame = 0;
}

int	handle_input(int key, t_game *game)
{
	int	moved;

	moved = 0;
	if (key == 119)
		moved = move_up(game);
	else if (key == 115)
		moved = move_down(game);
	else if (key == 97)
		moved = move_left(game);
	else if (key == 100)
		moved = move_right(game);
	else if (key == 65307 || key == 120)
		close_game(game);
	if (moved)
		switch_frame(game);
	return (0);
}
