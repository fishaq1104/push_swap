/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_hand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fishaq <fishaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:16:39 by fishaq            #+#    #+#             */
/*   Updated: 2024/05/21 21:55:38 by fishaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		current->nbr = 0;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

int	error_syntax(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		i++;
		if (str[i] == '\0' || !(str[i] >= '0' && str[i] <= '9'))
			return (1);
	}
	else if (!(str[i] >= '0' && str[i] <= '9'))
	{
		return (1);
	}
	i++;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

void	rotate_both(t_stack_node **a, t_stack_node **b,
		t_stack_node *cheap_node)
{
	while (*b != cheap_node->target_node && *a != cheap_node)
		rr(a, b, false);
	current_index(*a);
	current_index(*b);
}

void	free_matrix(char **av)
{
	size_t	i;

	if (av == NULL)
		return ;
	i = 0;
	while (av[i] != NULL)
	{
		free(av[i]);
		i++;
	}
	free(av);
}
