/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgagliar <kgagliar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 14:55:29 by kgagliar          #+#    #+#             */
/*   Updated: 2025/09/07 14:55:29 by kgagliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus/inc/so_long_bonus.h"

void	init_game(t_game *game, char *map_file)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		error_exit("Error: could not initialize MLX");
	read_map(game, map_file);
	validate_map(game);
	init_player_pos(game);
	init_enemy_pos(game);
	game->collected = 0;
	game->player_dir = DIR_DOWN;
	game->player_frame = 0;
	game->moves = 0;
	validate_path(game);
	game->win = mlx_new_window(game->mlx,
			game->width * TILE, game->height * TILE,
			"so_long");
	if (!game->win)
		error_exit("Error: could not create window");
	file_to_image(game);
	draw_map(game);
}

int	game_loop(t_game *game)
{
	static int	enemy_tick;

	if (++enemy_tick >= 1500)
	{
		move_enemies(game);
		enemy_tick = 0;
	}
	draw_map(game);
	display_moves(game);
	return (0);
}

static void	check_ber_extension(char *file)
{
	size_t	len;

	len = ft_strlen(file);
	if (len < 4 || ft_strncmp(file + len - 4, ".ber", 4) != 0)
		error_exit("Usage: ./so_long <map.ber>");
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		error_exit("Usage: ./so_long <map.ber>");
	check_ber_extension(argv[1]);
	ft_bzero(&game, sizeof(t_game));
	init_game(&game, argv[1]);
	mlx_key_hook(game.win, handle_input, &game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}
