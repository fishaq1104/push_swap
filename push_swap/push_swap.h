/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fishaq <fishaq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 22:33:47 by fishaq            #+#    #+#             */
/*   Updated: 2024/05/18 21:37:34 by fishaq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char					**my_split(char *str, char s);

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;

// handle errors
int						error_syntax(char *str);
int						error_reptition(t_stack_node *a, int nbr);
void					free_stack(t_stack_node **stack);

// Stack intialization
void					stack_init(t_stack_node **a, char **av); //, bool flag);
// nodes intialization

// stack utiles
t_stack_node			*find_last_node(t_stack_node *n);
bool					stack_sorted(t_stack_node *stack);
int						stack_len(t_stack_node *a);

// algorthims
void					sort_three(t_stack_node **a);
t_stack_node			*find_max(t_stack_node *a);
void					current_index(t_stack_node *stack);
t_stack_node			*find_min(t_stack_node *a);
t_stack_node			*get_cheapest(t_stack_node *stack);
void					prep_to_push(t_stack_node **stack,
							t_stack_node *top_node, char stack_name);
void					sort_stacks(t_stack_node **a, t_stack_node **b);
void					init_nodesa(t_stack_node *a, t_stack_node *b);
void					init_nodesb(t_stack_node *a, t_stack_node *b);
void					rotate_both(t_stack_node **a, t_stack_node **b,
							t_stack_node *cheap_node);

// commands
void					rrb(t_stack_node **b, bool print);
void					rra(t_stack_node **a, bool print);
void					rrr(t_stack_node **a, t_stack_node **b, bool print);
void					ra(t_stack_node **a, bool print);
void					rb(t_stack_node **b, bool print);
void					rr(t_stack_node **a, t_stack_node **b, bool print);
void					sa(t_stack_node **a, bool print);
void					sb(t_stack_node **b, bool print);
void					ss(t_stack_node **a, t_stack_node **b, bool print);
void					pb(t_stack_node **b, t_stack_node **a, bool print);
void					pa(t_stack_node **a, t_stack_node **b, bool print);

#endif
