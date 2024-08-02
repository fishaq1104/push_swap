/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   with_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fishaq <fishaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 20:20:50 by fishaq            #+#    #+#             */
/*   Updated: 2024/05/30 09:42:00 by fishaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strcat(char *dest, const char *s2)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	temp = dest;
	while (temp[i] != '\0')
		i++;
	while (s2[j] != '\0')
	{
		temp[i] = s2[j];
		i++;
		j++;
	}
	temp[i] = '\0';
	return (dest);
}

void	*ft_calloc(int count, int size)
{
	void	*str;

	if (size != 0 && count > INT_MAX / size)
	{
		return (NULL);
	}
	str = malloc(count * size);
	if (str != NULL)
		ft_bzero(str, count * size);
	else
		return (NULL);
	return (str);
}

void	*ft_bzero(void *str, int n)
{
	int		i;
	char	*char_str;

	i = 0;
	char_str = (char *)str;
	while (i < n)
	{
		char_str[i] = '\0';
		i++;
	}
	return (str);
}

int	ft_isspace(char c)
{
	if ((c == 32) || (c >= 9 && c <= 13))
		return (1);
	else
		return (0);
}

int	is_space(const char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (!ft_isspace((unsigned char)*str))
			return (0);
		str++;
	}
	return (1);
}
