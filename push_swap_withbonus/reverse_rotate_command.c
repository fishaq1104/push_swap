/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_command.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fishaq <fishaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 19:12:12 by fishaq            #+#    #+#             */
/*   Updated: 2024/05/22 17:49:03 by fishaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack_node **a)
{
	t_stack_node	*last_node;

	if (!*a || !(*a)->next)
		return ;
	last_node = find_last_node(*a);
	last_node->prev->next = NULL;
	last_node->next = *a;
	(*a)->prev = last_node;
	*a = last_node;
	last_node->prev = NULL;
}

void	rra(t_stack_node **a, bool print)
{
	reverse_rotate(a);
	if (!print)
		ft_printf("rra\n");
}

void	rrb(t_stack_node **b, bool print)
{
	reverse_rotate(b);
	if (!print)
		ft_printf("rrb\n");
}

void	rrr(t_stack_node **a, t_stack_node **b, bool print)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (!print)
		ft_printf("rrr\n");
}
