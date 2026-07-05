/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgagliar <kgagliar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 18:15:40 by kgagliar          #+#    #+#             */
/*   Updated: 2025/07/21 18:34:35 by kgagliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int nb)
{
	int	i;

	if (nb == -2147483648)
		return (11);
	i = 0;
	if (nb < 0)
	{
		nb = -nb;
		i++;
	}
	while (nb >= 10)
	{
		nb /= 10;
		i++;
	}
	return (i + 1);
}

static void	ft_number_conversion(int n, char *str, int nb)
{
	int	i;

	i = nb - 1;
	if (n < 0)
	{
		n = -n;
		str[0] = '-';
	}
	if (n == 0)
		str[i] = '0';
	else
	{
		while (n > 0)
		{
			str[i] = '0' + (n % 10);
			n /= 10;
			i--;
		}
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		count;

	count = ft_intlen(n);
	str = malloc(sizeof(char) * (count + 1));
	if (!str)
		return (NULL);
	str[count] = '\0';
	if (n == -2147483648)
	{
		ft_strlcpy(str, "-2147483648", count + 1);
		return (str);
	}
	ft_number_conversion(n, str, count);
	return (str);
}
