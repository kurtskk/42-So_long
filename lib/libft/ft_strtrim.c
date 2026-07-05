/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgagliar <kgagliar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 16:18:15 by kgagliar          #+#    #+#             */
/*   Updated: 2025/07/21 16:42:00 by kgagliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_in_set(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*strtrim;
	int		start;
	int		end;
	int		size;
	int		i;

	start = 0;
	while (s1[start] && ft_in_set(s1[start], set))
		start++;
	end = ft_strlen(s1) - 1;
	while (end >= start && ft_in_set(s1[end], set))
		end--;
	size = end - start + 1;
	strtrim = malloc((sizeof(char)) * (size + 1));
	if (!strtrim)
		return (NULL);
	i = 0;
	while (i < size)
	{
		strtrim[i] = s1[start + i];
		i++;
	}
	strtrim[i] = '\0';
	return (strtrim);
}
