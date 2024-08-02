/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fishaq <fishaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:43:55 by fishaq            #+#    #+#             */
/*   Updated: 2024/05/18 19:34:38 by fishaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack_node **a)
{
	t_stack_node	*temp;

	temp = find_max(*a);
	if (temp == *a)
		ra(a, false);
	else if ((*a)->next == temp)
		rra(a, false);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a, false);
}

t_stack_node	*find_max(t_stack_node *a)
{
	long			max;
	t_stack_node	*max_node;

	if (!a)
		return (NULL);
	max = LONG_MIN;
	while (a)
	{
		if (max < a->nbr)
		{
			max = a->nbr;
			max_node = a;
		}
		a = a->next;
	}
	return (max_node);
}

t_stack_node	*find_min(t_stack_node *a)
{
	long			min;
	t_stack_node	*min_node;

	if (!a)
		return (NULL);
	min = LONG_MAX;
	while (a)
	{
		if (min > a->nbr)
		{
			min = a->nbr;
			min_node = a;
		}
		a = a->next;
	}
	return (min_node);
}
