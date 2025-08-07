/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_nodes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 16:30:41 by mlima-si          #+#    #+#             */
/*   Updated: 2025/08/01 18:04:12 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_stack *a)
{
	int	i;

	i = 0;
	while (a)
	{
		i++;
		a = a->next;
	}
	return (i);
}

t_stack	*ft_find_last(t_stack *lst)
{
	if (!lst)
		return (lst);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

t_stack	*ft_find_biggest(t_stack *stack)
{
	t_stack	*biggest;

	if (!stack)
		return (stack);
	biggest = stack;
	while (stack->next)
	{
		stack = stack->next;
		if (stack->n > biggest->n)
			biggest = stack;
	}
	return (biggest);
}

t_stack	*ft_find_smallest(t_stack *stack)
{
	t_stack	*smallest;
	long	small_n;

	if (!stack)
		return (stack);
	small_n = LONG_MAX;
	while (stack)
	{
		if (stack->n < small_n)
		{
			small_n = stack->n;
			smallest = stack;
		}
		stack = stack->next;
	}
	return (smallest);
}

t_stack	*find_cheapest(t_stack *stack)
{
	if (!stack)
		return (stack);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
