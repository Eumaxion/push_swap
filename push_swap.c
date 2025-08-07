/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 17:56:25 by mlima-si          #+#    #+#             */
/*   Updated: 2025/08/01 17:59:44 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	smallest_top(t_stack **a)
{
	t_stack	*smallest;

	smallest = ft_find_smallest(*a);
	if (smallest->above_middle)
		while (*a != smallest)
			ra(a, 1);
	else
		while (*a != smallest)
			rra(a, 1);
}

void	sort_three(t_stack **stack)
{
	t_stack	*biggest;

	biggest = ft_find_biggest(*stack);
	if (*stack == biggest)
		ra(stack, 1);
	else if ((*stack)->next == biggest)
		rra(stack, 1);
	if ((*stack)->n > (*stack)->next->n)
		sa(stack, 1);
}

void	push_swap(t_stack **a, t_stack **b)
{
	int	len_stack_a;

	len_stack_a = stack_len(*a);
	if (len_stack_a-- > 3 && !stack_sorted(*a))
		pb(a, b, 1);
	if (len_stack_a-- > 3 && !stack_sorted(*a))
		pb(a, b, 1);
	while (len_stack_a-- > 3 && !stack_sorted(*a))
		pb(a, b, 1);
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		b_to_a(a, b);
	}
	set_index(*a);
	smallest_top(a);
}
