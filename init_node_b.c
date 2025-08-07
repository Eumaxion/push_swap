/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_node_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 17:57:40 by mlima-si          #+#    #+#             */
/*   Updated: 2025/08/01 17:58:28 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index(t_stack *stack)
{
	int	i;
	int	middle;

	if (!stack)
		return ;
	middle = stack_len(stack) / 2;
	i = 0;
	while (stack)
	{
		stack->index = i;
		if (i <= middle)
			stack->above_middle = 1;
		else
			stack->above_middle = 0;
		stack = stack->next;
		i++;
	}
}

void	set_target(t_stack *a, t_stack *b)
{
	t_stack	*copy_a;
	t_stack	*target_node;
	long	closer_bigger_n;

	while (b)
	{
		closer_bigger_n = LONG_MAX;
		copy_a = a;
		while (copy_a)
		{
			if (copy_a->n > b->n
				&& copy_a->n < closer_bigger_n)
			{
				closer_bigger_n = copy_a->n;
				target_node = copy_a;
			}
			copy_a = copy_a->next;
		}
		if (closer_bigger_n == LONG_MAX)
			b->target = ft_find_smallest(a);
		else
			b->target = target_node;
		b = b->next;
	}
}

void	set_price(t_stack *a, t_stack *b)
{
	int	len_stack_a;
	int	len_stack_b;

	len_stack_a = stack_len(a);
	len_stack_b = stack_len(b);
	while (b)
	{
		b->p_cost = b->index;
		if (!(b->above_middle))
			b->p_cost = len_stack_b - (b->index);
		if (b->target->above_middle)
			b->p_cost += b->target->index;
		else
			b->p_cost += len_stack_a - (b->target->index);
		b = b->next;
	}
}

void	set_cheapest(t_stack *stack)
{
	long		lower_value;
	t_stack		*cheapest_node;

	if (!stack)
		return ;
	lower_value = LONG_MAX;
	while (stack)
	{
		if (stack->p_cost < lower_value)
		{
			lower_value = stack->p_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = 1;
}

void	init_nodes_b(t_stack *a, t_stack *b)
{
	set_index(a);
	set_index(b);
	set_target(a, b);
	set_price(a, b);
	set_cheapest(b);
}
