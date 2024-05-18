/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fishaq <fishaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 16:14:04 by fishaq            #+#    #+#             */
/*   Updated: 2024/05/18 21:40:51 by fishaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate_both(t_stack_node **a, t_stack_node **b,
		t_stack_node *cheap_node)
{
	while (*b != cheap_node->target_node && *a != cheap_node)
		rrr(a, b, false);
	current_index(*a);
	current_index(*b);
}

static void	move_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheap_node;

	cheap_node = get_cheapest(*a);
	if (cheap_node->above_median && cheap_node->target_node->above_median)
		rotate_both(a, b, cheap_node);
	else if (!(cheap_node->above_median)
		&& !(cheap_node->target_node->above_median))
		rev_rotate_both(a, b, cheap_node);
	prep_to_push(a, cheap_node, 'a');
	prep_to_push(b, cheap_node->target_node, 'b');
	pb(b, a, false);
}

static void	move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	prep_to_push(a, (*b)->target_node, 'a');
	pa(a, b, false);
}

static void	min_on_top(t_stack_node **a)
{
	while ((*a)->nbr != find_min(*a)->nbr)
	{
		if (find_min(*a)->above_median)
			ra(a, false);
		else
			rra(a, false);
	}
}

void	sort_stacks(t_stack_node **a, t_stack_node **b)
{
	int	len;

	len = stack_len(*a);
	if (len-- > 3 && !stack_sorted(*a))
		pb(b, a, false);
	if (len-- > 3 && !stack_sorted(*a))
		pb(b, a, false);
	while (len-- > 3 && !stack_sorted(*a))
	{
		init_nodesa(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_nodesb(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	min_on_top(a);
}
