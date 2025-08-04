/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 15:17:16 by mlima-si          #+#    #+#             */
/*   Updated: 2025/08/01 18:11:48 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_free(t_stack	**a, char **argv, int flag_argc)
{
	int	i;

	if (flag_argc)
	{
		i = 0;
		if (argv == NULL || *argv == NULL)
			return ;
		while (argv[i])
			free(argv[i++]);
		free(argv);
	}
	if (a != NULL)
		free_stack(*a);
	write(2, "Error\n", 6);
	exit(2);
}

void	free_stack(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}

void	free_arg(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		free(argv[i++]);
	free(argv);
}

void	print_nodes(t_stack *a)
{
	while (a)
	{
		printf("%d || ", a->n);
		a = a->next;
	}
	printf("\n");
}
