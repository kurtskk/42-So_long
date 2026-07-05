/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgagliar <kgagliar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 20:56:54 by kgagliar          #+#    #+#             */
/*   Updated: 2025/07/21 17:50:06 by kgagliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nprt)
{
	int	i;
	int	result;
	int	signal;

	i = 0;
	result = 0;
	signal = 1;
	while ((nprt[i] >= 9 && nprt[i] <= 13) || nprt[i] == 32)
		i++;
	if (nprt[i] == '-' || nprt[i] == '+')
	{
		if (nprt[i] == '-')
			signal *= -1;
		i++;
	}
	while (nprt[i] >= '0' && nprt[i] <= '9')
	{
		result = result * 10 + (nprt[i] - '0');
		i++;
	}
	return (result * signal);
}
