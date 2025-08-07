/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 15:17:22 by mlima-si          #+#    #+#             */
/*   Updated: 2025/08/01 18:11:01 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2 || (argc == 2 && (!argv[1] || !argv[1][0])))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (argc == 2)
		argv = ft_split(argv[1], 32);
	build_stack(&stack_a, argv, argc == 2);
	if (!stack_sorted(stack_a))
	{
		if (stack_len(stack_a) == 2)
			sa(&stack_a, 1);
		else if (stack_len(stack_a) == 3)
			sort_three(&stack_a);
		else
			push_swap(&stack_a, &stack_b);
	}
	free_stack(stack_a);
	return (0);
}
