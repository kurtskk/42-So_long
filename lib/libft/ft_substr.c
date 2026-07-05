/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgagliar <kgagliar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 20:26:04 by kgagliar          #+#    #+#             */
/*   Updated: 2025/07/22 18:08:00 by kgagliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	sub_len;

	if (!s)
		return (NULL);
	sub_len = ft_strlen(s);
	if (start >= sub_len)
		return (ft_strdup(""));
	if (start + len > sub_len)
		len = sub_len - start;
	sub_str = (char *)malloc(len + 1);
	if (!sub_str)
		return (NULL);
	ft_strlcpy(sub_str, s + start, len + 1);
	return (sub_str);
}
