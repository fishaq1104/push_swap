/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fishaq <fishaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:49:54 by fishaq            #+#    #+#             */
/*   Updated: 2024/07/31 15:49:09 by fishaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"
# include <fcntl.h>
# include <limits.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 42

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

char				*get_next_line(int fd);
size_t				ft_stlen(char const *str);
char				*ft_strchr(char const *str, int c);
char				*ft_strcpy(char *dest, char *src);
char				*ft_strdup(char const *src);
char				*ft_strjoin(char const *s1, char const *s2);
char				**get_strings(int ac, char **av);
char				*concat(int ac, char **av, int *len);
int					ft_strlen(const char *s);
void				check_spaces(int ac, char **av);
int					ft_strncmp(const char *s1, const char *s2, size_t n);

#endif