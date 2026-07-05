/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgagliar <kgagliar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 20:58:39 by kgagliar          #+#    #+#             */
/*   Updated: 2025/07/18 14:41:39 by kgagliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*str;
	size_t	j;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
		i++;
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	j = 0;
	while (s[j] != '\0')
	{
		str[j] = f(j, s[j]);
		j++;
	}
	str[j] = '\0';
	return (str);
}
