/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 16:30:41 by mlima-si          #+#    #+#             */
/*   Updated: 2025/07/27 15:22:55 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_find_last(t_stack *lst)
{
	if (!lst)
		return (lst);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
//----------------------- exclude later -----------------------//
void	print_nodes(t_stack *a)
{
	while (a->next != NULL)
	{
		printf("%d || ", a->n);
		a = a->next;
	}
	printf("%d\n", a->n);
}
//---------------------^^ exclude later ^^---------------------//
int	stack_sorted(t_stack *a)
{
	int	n;

	n = a->n;
	while (a->next)
	{
		a = a->next;
		if (n > a->n)
			return (0);
		n = a->n;
	}
	return (1);
}

int	stack_len(t_stack *a)
{
	int	i;

	i = 1;
	while (a->next)
	{
		a = a->next;
		i++;
	}
	return (i);
}
