/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgagliar <kgagliar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:03:19 by kgagliar          #+#    #+#             */
/*   Updated: 2025/07/17 15:17:09 by kgagliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1_uc;
	const unsigned char	*s2_uc;
	size_t				i;

	s1_uc = (const unsigned char *)s1;
	s2_uc = (const unsigned char *)s2;
	i = 0;
	while (i < n && s1_uc[i] == s2_uc[i])
		i++;
	if (i == n)
		return (0);
	return (s1_uc[i] - s2_uc[i]);
}
