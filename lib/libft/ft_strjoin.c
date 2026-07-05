/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgagliar <kgagliar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 15:45:48 by kgagliar          #+#    #+#             */
/*   Updated: 2025/07/23 20:51:37 by kgagliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		s1_len;
	int		s2_len;
	char	*str;

	s1_len = 0;
	s2_len = 0;
	if (!s1 && !s2)
		return (NULL);
	while (s1[s1_len] != 0)
		s1_len++;
	while (s2[s2_len] != 0)
		s2_len++;
	str = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (++i < s1_len)
		str[i] = s1[i];
	i = -1;
	while (++i < s2_len)
		str[s1_len + i] = s2[i];
	str[s1_len + s2_len] = '\0';
	return (str);
}
