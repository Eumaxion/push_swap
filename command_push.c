/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 15:45:22 by mlima-si          #+#    #+#             */
/*   Updated: 2025/08/01 17:53:01 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **dest, t_stack **source)
{
	t_stack	*tmp_node;

	if (!source || !*source)
		return ;
	tmp_node = *source;
	*source = tmp_node->next;
	if (*source)
		(*source)->prev = NULL;
	tmp_node->next = *dest;
	if (*dest)
		(*dest)->prev = tmp_node;
	tmp_node->prev = NULL;
	*dest = tmp_node;
}

void	pa(t_stack **a, t_stack **b, int print)
{
	push(a, b);
	if (print)
		write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b, int print)
{
	push(b, a);
	if (print)
		write(1, "pb\n", 3);
}
