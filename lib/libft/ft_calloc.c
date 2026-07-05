/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgagliar <kgagliar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 19:32:40 by kgagliar          #+#    #+#             */
/*   Updated: 2025/07/16 16:42:31 by kgagliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			value;
	void			*ptr;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb != 0 && size > ((size_t)(-1)) / nmemb)
		return (NULL);
	value = nmemb * size;
	ptr = malloc(value);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, value);
	return (ptr);
}
