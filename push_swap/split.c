/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fishaq <fishaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 23:38:25 by fishaq            #+#    #+#             */
/*   Updated: 2024/05/14 18:16:39 by fishaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	word_count(char *s, char c)
{
	int		count;
	int		j;
	bool	inside_word;

	count = 0;
	j = 0;
	while (s[j])
	{
		inside_word = false;
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
		{
			if (!inside_word)
			{
				count++;
				inside_word = true;
			}
			j++;
		}
	}
	return (count);
}

static	char	*get_next_word(char *str, char c)
{
	static int	i = 0;
	char		*word;
	int			len;
	int			j;

	j = 0;
	len = 0;
	while (str[i] == c)
		i++;
	while ((str[i + len] != c) && str[i + len])
		len++;
	word = malloc(sizeof(char) * (size_t)(len + 1));
	if (!word)
		return (NULL);
	while ((str[i] != c) && str[i])
		word[j++] = str[i++];
	word[j] = '\0';
	return (word); 
}

char	**my_split(char *str, char s)
{
	int		countword;
	char	**word;
	int		i;

	i = 0;
	countword = word_count(str, s);
	if (!countword)
		exit(1);
	word = (char **)malloc((size_t)(countword + 2) * sizeof(char *));
	if (!word)
		return (NULL);
	while (countword-- >= 0)
	{
		if (i == 0)
		{
			word[i] = malloc(sizeof(char));
			if (!word)
				return (NULL);
			word[i++][0] = '\0';
			continue ;
		}
		word[i++] = get_next_word(str, s);
	}
	word[i] = NULL;
	return (word);
}
