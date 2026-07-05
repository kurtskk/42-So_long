/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgagliar <kgagliar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 14:57:29 by kgagliar          #+#    #+#             */
/*   Updated: 2025/09/07 14:57:29 by kgagliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../bonus/inc/so_long_bonus.h"

void	error_exit(char *msg)
{
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	exit(1);
}

void	print_moves(t_game *game)
{
	ft_putstr_fd("Moves: ", 1);
	ft_putnbr_fd(game->moves, 1);
	ft_putchar_fd('\n', 1);
}

void	display_moves(t_game *game)
{
	char	*str;
	char	*tmp;

	tmp = ft_itoa(game->moves);
	if (!tmp)
		error_exit("Error building moves string");
	str = ft_strjoin("Moves: ", tmp);
	free(tmp);
	if (!str)
		error_exit("Error converting number to string");
	mlx_string_put(game->mlx, game->win, 10, 20, 0xAAAAAA, str);
	free(str);
}

void	free_map(t_game *game)
{
	int	i;

	if (!game->map)
		return ;
	i = 0;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
}
