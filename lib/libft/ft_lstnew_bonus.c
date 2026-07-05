/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgagliar <kgagliar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:32:29 by kgagliar          #+#    #+#             */
/*   Updated: 2025/07/23 22:22:22 by kgagliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*head;

	head = malloc((sizeof(t_list)));
	if (!head)
		return (NULL);
	head->content = content;
	head->next = NULL;
	return (head);
}
