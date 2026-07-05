/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgagliar <kgagliar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 16:13:50 by kgagliar          #+#    #+#             */
/*   Updated: 2025/07/21 16:45:14 by kgagliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		j;
	int		i;
	char	*dest;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	dest = malloc(((i + 1) * sizeof(char)));
	if (!dest)
		return (NULL);
	j = 0;
	while (s[j] != '\0')
	{
		dest[j] = s[j];
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
