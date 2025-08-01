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

void	init_nodes_b(t_stack *a, t_stack *b)
{
	set_index(a);
	set_index(b);
	target_in_b(a, b);
}

void	target_in_b(t_stack *a, t_stack *b)
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
