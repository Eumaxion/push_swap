/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_node_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 18:06:25 by mlima-si          #+#    #+#             */
/*   Updated: 2025/08/01 18:06:26 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_nodes_a(t_stack *a, t_stack *b)
{
	set_index(a);
	set_index(b);
	target_in_a(a, b);
	set_price(a, b);
	find_cheapest(a);
}

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

void	target_in_a(t_stack *a, t_stack *b)
{
	t_stack	*copy_b;
	t_stack	*target_node;
	long	closer_smaller_n;

	while (a)
	{
		closer_smaller_n = LONG_MIN;
		copy_b = b;
		while (copy_b)
		{
			if (copy_b->n < a->n
				&& copy_b->n > closer_smaller_n)
			{
				closer_smaller_n = copy_b->n;
				target_node = copy_b;
			}
			copy_b = copy_b->next;
		}
		if (closer_smaller_n == LONG_MIN)
			a->target = ft_find_biggest(b);
		else
			a->target = target_node;
		a = a->next;
	}
}

void	set_price(t_stack *a, t_stack *b)
{
	int	len_stack_a;
	int	len_stack_b;

	len_stack_a = stack_len(a);
	len_stack_b = stack_len(b);
	while (a)
	{
		a->p_cost = a->index;
		if (!(a->above_middle))
			a->p_cost = len_stack_a - (a->index);
		if (a->target->above_middle)
			a->p_cost += a->target->index;
		else
			a->p_cost += len_stack_b - (a->target->index);
		a = a->next;
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
