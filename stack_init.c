/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 15:17:18 by mlima-si          #+#    #+#             */
/*   Updated: 2025/08/01 18:03:18 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_valid(char *nbr)
{
	int	i;

	i = 0;
	if (nbr[i] == '+' || nbr[i] == '-')
		i++;
	if (!nbr[i])
		return (0);
	while (ft_isdigit(nbr[i]))
		i++;
	return (nbr[i] == 0);
}

static int	check_repeated(t_stack	*a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->n == n)
			return (1);
		a = a->next;
	}
	return (0);
}

static void	add_node(t_stack **a, int n)
{
	t_stack	*node;
	t_stack	*last_node;

	if (a == NULL)
		return ;
	node = malloc(sizeof(t_stack));
	if (node == NULL)
		return ;
	node->next = NULL;
	node->n = n;
	if (*a == NULL)
	{
		*a = node;
		node->prev = NULL;
	}
	else
	{
		last_node = ft_find_last(*a);
		last_node->next = node;
		node->prev = last_node;
	}
}

int	stack_sorted(t_stack *a)
{
	if (!a)
		return (1);
	while (a->next)
	{
		if (a->n > a->next->n)
			return (0);
		a = a->next;
	}
	return (1);
}

void	build_stack(t_stack **a, char **argv, int flag_argc)
{
	long	n;
	int		i;

	i = 1;
	if (flag_argc)
		i--;
	while (argv[i])
	{
		if (!is_valid(argv[i]))
			error_free(a, argv, flag_argc);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			error_free(a, argv, flag_argc);
		if (check_repeated(*a, (int)n))
			error_free(a, argv, flag_argc);
		add_node(a, (int)n);
		i++;
	}
	if (flag_argc)
		free_arg(argv);
}
