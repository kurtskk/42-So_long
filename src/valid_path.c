/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgagliar <kgagliar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 15:48:22 by kgagliar          #+#    #+#             */
/*   Updated: 2025/09/07 15:48:22 by kgagliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static void	dfs(char **map, int y, int x, t_found *found)
{
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	if (map[y][x] == 'C')
		found->c++;
	if (map[y][x] == 'E')
		found->e++;
	map[y][x] = 'V';
	dfs(map, y - 1, x, found);
	dfs(map, y + 1, x, found);
	dfs(map, y, x - 1, found);
	dfs(map, y, x + 1, found);
}

static char	**copy_map(t_game *game)
{
	char	**map_copy;
	int		y;

	y = 0;
	map_copy = malloc(sizeof(char *) * (game->height + 1));
	if (!map_copy)
		error_exit("Error: failed to allocate temporary map");
	while (y < game->height)
	{
		map_copy[y] = ft_strdup(game->map[y]);
		if (!map_copy[y])
			error_exit("Error: failed to duplicate map line");
		y++;
	}
	map_copy[y] = NULL;
	return (map_copy);
}

static void	free_map_copy(char **map_copy, int height)
{
	int	y;

	y = 0;
	while (y < height)
	{
		free(map_copy[y]);
		y++;
	}
	free(map_copy);
}

void	validate_path(t_game *game)
{
	char	**map_copy;
	t_found	found;

	found.c = 0;
	found.e = 0;
	map_copy = copy_map(game);
	dfs(map_copy, game->y, game->x, &found);
	free_map_copy(map_copy, game->height);
	if (found.c != game->c || found.e != game->e)
		error_exit("Error\nInvalid map: unreachable path");
}
