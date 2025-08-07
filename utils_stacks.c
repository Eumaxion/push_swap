/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 18:04:56 by mlima-si          #+#    #+#             */
/*   Updated: 2025/08/01 18:07:00 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*a != cheapest->target && *b != cheapest)
		rr(a, b, 1);
	set_index(*a);
	set_index(*b);
}

void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*a != cheapest->target && *b != cheapest)
		rrr(a, b, 1);
	set_index(*a);
	set_index(*b);
}

void	set_for_push(t_stack **stack, t_stack *first_node, char name)
{
	int	above_middle;

	above_middle = first_node->above_middle;
	while (*stack != first_node)
	{
		if (name == 'a')
		{
			if (above_middle)
				ra(stack, 1);
			else
				rra(stack, 1);
		}
		else if (name == 'b')
		{
			if (above_middle)
				rb(stack, 1);
			else
				rrb(stack, 1);
		}
	}
}

void	b_to_a(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = find_cheapest(*b);
	if (cheapest_node->above_middle
		&& cheapest_node->target->above_middle)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_middle)
		&& !(cheapest_node->target->above_middle))
		rev_rotate_both(a, b, cheapest_node);
	set_for_push(b, cheapest_node, 'b');
	set_for_push(a, cheapest_node->target, 'a');
	pa(a, b, 1);
}
