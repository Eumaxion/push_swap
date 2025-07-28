/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 15:45:30 by mlima-si          #+#    #+#             */
/*   Updated: 2025/07/27 15:19:22 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **head)
{
	t_stack *first;
	t_stack *second;

	if (!head || !*head || !(*head)->next)
		return ;
	first = *head;
	second = (*head)->next;
	first->next = second->next;
	first->prev = second;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	*head = second;
}

void	sa(t_stack **a)
{
	swap(a);
	write(1, "sa\n", 3);
} 

void	sb(t_stack **b)
{
	swap(b);
	write(1, "sa\n", 3);
} 

void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
} 
