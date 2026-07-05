/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgagliar <kgagliar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 16:03:41 by kgagliar          #+#    #+#             */
/*   Updated: 2025/07/21 18:48:05 by kgagliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free_split(char **split, int word_index)
{
	while (word_index-- > 0)
		free(split[word_index]);
	free(split);
}

static int	ft_words(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static char	*ft_words_split(char const *s, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((sizeof(char) * (end - start + 1)));
	if (!word)
		return (NULL);
	while (start < end)
	{
		word[i] = s[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

static int	ft_fill_split(char **split, char const *s, char c)
{
	int	i;
	int	start;
	int	word_index;

	i = 0;
	start = -1;
	word_index = 0;
	while (i <= (int)ft_strlen(s))
	{
		if (s[i] != c && start < 0)
			start = i;
		else if ((s[i] == c || i == (int)ft_strlen(s)) && start >= 0)
		{
			split[word_index] = ft_words_split(s, start, i);
			if (!split[word_index])
				return (ft_free_split(split, word_index), 0);
			word_index++;
			start = -1;
		}
		i++;
	}
	split[word_index] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		len;
	char	**split;

	if (!s)
		return (NULL);
	len = ft_words(s, c);
	split = (char **)malloc(sizeof(char *) * (len + 1));
	if (!split)
		return (NULL);
	if (!ft_fill_split(split, s, c))
		return (NULL);
	return (split);
}
