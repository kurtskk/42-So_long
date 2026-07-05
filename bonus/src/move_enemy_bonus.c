/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgagliar <kgagliar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 14:56:12 by kgagliar          #+#    #+#             */
/*   Updated: 2025/09/07 14:56:12 by kgagliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus/inc/so_long_bonus.h"

static int	get_next_y(t_enemy *enemy)
{
	if (enemy->dir == 1)
		return (enemy->y + 1);
	return (enemy->y - 1);
}

static void	switch_enemy_dir(t_enemy *enemy)
{
	if (enemy->dir == 1)
		enemy->dir = 0;
	else
		enemy->dir = 1;
}

static int	check_collision(t_game *game, t_enemy *enemy, int prev_y)
{
	int	y_min;
	int	y_max;

	y_min = prev_y;
	y_max = enemy->y;
	if (y_min > y_max)
	{
		y_min = enemy->y;
		y_max = prev_y;
	}
	if (enemy->x == game->x && game->y >= y_min && game->y <= y_max)
		return (1);
	return (0);
}

static void	move_single_enemy(t_game *game, int i)
{
	t_enemy	*enemy;
	int		next_y;
	int		prev_y;

	enemy = &game->enemies[i];
	prev_y = enemy->y;
	next_y = get_next_y(enemy);
	if (game->map[next_y][enemy->x] == '1')
	{
		switch_enemy_dir(enemy);
		return ;
	}
	enemy->y = next_y;
	if (check_collision(game, enemy, prev_y))
		close_game(game);
	if (enemy->frame == 0)
		enemy->frame = 1;
	else
		enemy->frame = 0;
}

void	move_enemies(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->enemy_count)
	{
		move_single_enemy(game, i);
		i++;
	}
}
