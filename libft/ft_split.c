/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsylvain <dsylvain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 09:45:20 by dan               #+#    #+#             */
/*   Updated: 2023/11/29 12:16:08 by dsylvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	const char	*start = s;
	int			word_qtty;

	word_qtty = 0;
	while (*s)
	{
		if (*s != c && (s == start || *(s - 1) == c))
			word_qtty++;
		s++;
	}
	return (word_qtty);
}

static char	*add_new_word(char const **s, char c)
{
	char	*word_start;
	char	*word;
	int		word_len;
	int		i;

	while (**s == c)
		(*s)++;
	word_start = (char *)*s;
	word_len = 0;
	while (**s && **s != c)
	{
		word_len++;
		(*s)++;
	}
	word = (char *)malloc(sizeof(char) * (word_len + 1));
	if (!word)
		return (NULL);
	word[word_len] = '\0';
	i = 0;
	while (i < word_len)
	{
		word[i] = word_start[i];
		i++;
	}
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		word_qtty;
	int		i;

	if (!s)
		return (NULL);
	word_qtty = count_words(s, c);
	tab = (char **)ft_calloc((word_qtty + 1), sizeof(char *));
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (i < word_qtty)
	{
		tab[i] = add_new_word(&s, c);
		if (!tab[i])
		{
			while (i >= 0)
				free(tab[i--]);
			free(tab);
			return (NULL);
		}
		i++;
	}
	return (tab);
}
