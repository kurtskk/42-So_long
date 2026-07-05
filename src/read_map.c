/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgagliar <kgagliar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 15:47:39 by kgagliar          #+#    #+#             */
/*   Updated: 2025/09/07 15:47:39 by kgagliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static char	*read_file(char *file)
{
	int		fd;
	char	*line;
	char	*tmp;
	char	*map_str;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_exit("ERROR: COULD NOT OPEN MAP FILE");
	map_str = ft_strdup("");
	if (!map_str)
		error_exit("ERROR: MEMORY ALLOCATION FAILED");
	line = get_next_line(fd);
	while (line != NULL)
	{
		tmp = ft_strjoin(map_str, line);
		if (!tmp)
			error_exit("ERROR: FAILED TO CONCATENATE LINES");
		free(map_str);
		free(line);
		map_str = tmp;
		line = get_next_line(fd);
	}
	close(fd);
	return (map_str);
}

void	read_map(t_game *game, char *file)
{
	char	*map_str;
	int		i;

	map_str = read_file(file);
	game->map = ft_split(map_str, '\n');
	free(map_str);
	if (!game->map || !game->map[0])
		error_exit("ERROR: INVALID MAP");
	i = 0;
	while (game->map[i])
		i++;
	game->height = i;
	game->width = ft_strlen(game->map[0]);
}

void	init_player_pos(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == 'P')
			{
				game->y = y;
				game->x = x;
				return ;
			}
			x++;
		}
		y++;
	}
	error_exit("ERROR: PLAYER NOT FOUND IN MAP");
}
