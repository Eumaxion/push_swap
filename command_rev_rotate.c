/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 15:46:09 by mlima-si          #+#    #+#             */
/*   Updated: 2025/07/27 15:10:55 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate(t_stack **head)
{
	t_stack	*first;
	t_stack	*last;

	if (!head || !*head || !(*head)->next)
		return ;

	first = *head;
	last = ft_find_last(*head);
	
	last->prev->next = NULL;
	last->next = first;
	last->prev = NULL;
	first->prev = last;
	*head = last;
}

void	rra(t_stack **a, int print)
{
	rev_rotate(a);
	if (print)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b, int print)
{
	rev_rotate(b);
	if (print)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b, int print)
{
	rev_rotate(a);
	rev_rotate(b);
	if (print)
		write(1, "rrr\n", 4);
}

void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*b != cheapest->target && *a != cheapest)
		rrr(a, b, 1);
	set_index(*a);
	set_index(*b);
}
