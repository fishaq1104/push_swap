/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fishaq <fishaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 18:27:42 by fishaq            #+#    #+#             */
/*   Updated: 2024/07/31 15:44:43 by fishaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static	void	write_k(t_stack_node *a, char *str)
{
	int		len;

	len = stack_len(a);
	free(str);
	if (stack_sorted(a) && stack_len(a) == len)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

static void	error(t_stack_node **a, t_stack_node **b, char *com, char **str)
{
	free(com);
	free_stack(a);
	free_stack(b);
	free_matrix(str);
	write(2, "Error\n", 6);
	exit(1);
}

static void	parse_command(t_stack_node **a, t_stack_node **b, char *command,
					char **str)
{
	if (!ft_strncmp(command, "pa", 100))
		pa(a, b, true);
	else if (!ft_strncmp(command, "pb", 100))
		pb(b, a, true);
	else if (!ft_strncmp(command, "sa", 100))
		sa(a, true);
	else if (!ft_strncmp(command, "sb", 100))
		sb(b, true);
	else if (!ft_strncmp(command, "ss", 100))
		ss(a, b, true);
	else if (!ft_strncmp(command, "ra", 100))
		ra(a, true);
	else if (!ft_strncmp(command, "rb", 100))
		rb(b, true);
	else if (!ft_strncmp(command, "rr", 100))
		rr(a, b, true);
	else if (!ft_strncmp(command, "rra", 100))
		rra(a, true);
	else if (!ft_strncmp(command, "rrb", 100))
		rrb(b, true);
	else if (!ft_strncmp(command, "rrr", 100))
		rrr(a, b, true);
	else
		error(a, b, command, str);
}

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			*line;
	char			**str;

	a = NULL;
	b = NULL;
	str = NULL;
	if (ac == 1 || (2 == ac && !av[1][0]))
		return (1);
	check_spaces(ac, av);
	if (ac >= 2)
		str = get_strings(ac, av);
	stack_init(&a, (str + 1), str);
	line = get_next_line(0);
	while ((line))
	{
		parse_command(&a, &b, line, str);
		free(line);
		line = get_next_line(0);
	}
	write_k(a, line);
	free_matrix(str);
	free_stack(&a);
	return (0);
}
