/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgagliar <kgagliar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:34:54 by kgagliar          #+#    #+#             */
/*   Updated: 2025/07/23 22:19:32 by kgagliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (!s || fd < 0)
		return ;
	while (*s)
		ft_putchar_fd(*s++, fd);
	ft_putchar_fd('\n', fd);
}
