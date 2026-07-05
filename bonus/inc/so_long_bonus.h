/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgagliar <kgagliar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 14:57:10 by kgagliar          #+#    #+#             */
/*   Updated: 2025/09/07 14:57:10 by kgagliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../lib/libft/libft.h"
# include "../lib/libft/get_next_line.h"
# include "../minilibx-linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define TILE       60
# define IMG_PXL    60
# define DIR_UP     0
# define DIR_DOWN   1
# define DIR_LEFT   2
# define DIR_RIGHT  3

typedef struct s_found
{
	int	c;
	int	e;
}	t_found;

typedef struct s_img
{
	void	*empty;
	void	*collectible;
	void	*wall;
	void	*exit;
	void	*exit_closed;
	void	*player_left1;
	void	*player_right1;
	void	*player_up1;
	void	*player_down1;
	void	*player_left2;
	void	*player_right2;
	void	*player_up2;
	void	*player_down2;
}	t_img;

typedef struct s_enemy
{
	int		x;
	int		y;
	int		dir;
	void	*up1;
	void	*up2;
	void	*down1;
	void	*down2;
	int		frame;
}	t_enemy;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		width;
	int		height;
	int		x;
	int		y;
	int		player_dir;
	int		player_frame;
	int		moves;
	int		c;
	int		collected;
	int		e;
	int		p;
	t_img	img;
	t_enemy	*enemies;
	int		enemy_count;
}	t_game;

void	read_map(t_game *game, char *file);
void	init_player_pos(t_game *game);
void	validate_map(t_game *game);
void	validate_path(t_game *game);
void	free_map(t_game *game);
void	init_enemy_pos(t_game *game);
void	draw_map(t_game *game);
void	file_to_image(t_game *game);
void	*dir_player(t_game *game);
int		move_up(t_game *game);
int		move_down(t_game *game);
int		move_left(t_game *game);
int		move_right(t_game *game);
void	update_position(t_game *game, int new_x, int new_y);
void	move_enemies(t_game *game);
int		handle_input(int key, t_game *game);
int		game_loop(t_game *game);
void	error_exit(char *msg);
void	free_images(t_game *game);
int		close_game(t_game *game);
void	print_moves(t_game *game);
void	display_moves(t_game *game);

#endif
