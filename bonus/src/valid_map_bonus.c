/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgagliar <kgagliar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 14:57:42 by kgagliar          #+#    #+#             */
/*   Updated: 2025/09/07 14:57:42 by kgagliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus/inc/so_long_bonus.h"

static void	check_map_rectangular(t_game *game)
{
	int	i;
	int	len;

	len = ft_strlen(game->map[0]);
	i = 1;
	while (game->map[i])
	{
		if ((int)ft_strlen(game->map[i]) != len)
			error_exit("Error: Map is not rectangular");
		i++;
	}
	game->width = len;
	game->height = i;
}

static void	check_map_walls(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->width)
	{
		if (game->map[0][i] != '1' || game->map[game->height - 1][i] != '1')
			error_exit("Error: Horizontal borders must be walls");
		i++;
	}
	i = 0;
	while (i < game->height)
	{
		if (game->map[i][0] != '1' || game->map[i][game->width - 1] != '1')
			error_exit("Error: Vertical borders must be walls");
		i++;
	}
}

static void	count_chars(t_game *game, int *p, int *c, int *e)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (!ft_strchr("01PCEM", game->map[y][x]))
				error_exit("Error: Invalid character in map");
			if (game->map[y][x] == 'P')
				(*p)++;
			else if (game->map[y][x] == 'E')
				(*e)++;
			else if (game->map[y][x] == 'C')
				(*c)++;
			x++;
		}
		y++;
	}
}

static void	check_chars(t_game *game)
{
	int	p;
	int	c;
	int	e;

	p = 0;
	c = 0;
	e = 0;
	count_chars(game, &p, &c, &e);
	if (p != 1 || e < 1 || c < 1)
		error_exit("Error: Incorrect number of P, C, or E");
	game->p = p;
	game->e = e;
	game->c = c;
}

void	validate_map(t_game *game)
{
	check_map_rectangular(game);
	check_chars(game);
	check_map_walls(game);
}
