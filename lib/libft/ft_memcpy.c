/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgagliar <kgagliar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 15:37:37 by kgagliar          #+#    #+#             */
/*   Updated: 2025/07/23 21:26:13 by kgagliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	const unsigned char	*src_uc;
	unsigned char		*dest_uc;

	if (dest == src || n == 0)
		return (dest);
	i = 0;
	src_uc = (const unsigned char *)src;
	dest_uc = (unsigned char *)dest;
	while (i < n)
	{
		dest_uc[i] = src_uc[i];
		i++;
	}
	return (dest);
}
