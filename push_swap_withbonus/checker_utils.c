/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fishaq <fishaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 15:26:04 by fishaq            #+#    #+#             */
/*   Updated: 2024/07/31 15:36:13 by fishaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	check_spaces(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (is_space(av[i]))
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		i++;
	}
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != 0)
	{
		i++;
	}
	return (i);
}

char	*concat(int ac, char **av, int *len)
{
	int		i;
	char	*str;

	str = NULL;
	i = 1;
	*len = 1;
	while (i < ac)
	{
		*len += ft_strlen(av[i]) + 1;
		i++;
	}
	str = (char *)ft_calloc((sizeof(char) * (*len)), *len);
	if (!str)
		return (NULL);
	str[*len - 1] = '\0';
	i = 1;
	while (i < ac)
	{
		ft_strcat(str, av[i]);
		if (i < ac - 1)
			ft_strcat(str, " ");
		i++;
	}
	return (str);
}

char	**get_strings(int ac, char **av)
{
	int		len;
	char	**string;
	char	*word;

	len = 0;
	string = NULL;
	word = NULL;
	if (ac > 2)
		word = concat(ac, av, &len);
	else
		word = av[1];
	string = my_split(word, ' ');
	if (ac > 2)
		free(word);
	return (string);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*c1;
	unsigned char	*c2;

	i = 0;
	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	if (!s1)
		return (1);
	while (i < n)
	{
		if (!c2[i] && !c1[i])
			return (0);
		if (c1[i] != c2[i])
			return (c1[i] - c2[i]);
		i++;
	}
	return (0);
}
