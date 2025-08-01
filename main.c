/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 15:17:22 by mlima-si          #+#    #+#             */
/*   Updated: 2025/07/31 17:06:38 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if(argc < 2 || (argc == 2 && !argv[1][0]))
	{
		write(1, "Error\n", 7);
		return(1);
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
	print_nodes(stack_a);
	free_stack(stack_a);
	return (0);
}

//----------------------- exclude later -----------------------//
void	print_nodes(t_stack *a)
{
	while (a)
	{
		printf("%d || ", a->n);
		a = a->next;
	}
	printf("\n");
}
//---------------------^^ exclude later ^^---------------------//

/* 		printf("Before sorting: \n");
		print_nodes(stack_a); //<<<<<< exclude later
				else
		{
			pb(&stack_a, &stack_b);
			pb(&stack_a, &stack_b);
			print_nodes(stack_b); //<<<<<< exclude later
		
		printf("\nAfter sorting: \n");
		print_nodes(stack_a); //<<<<<< exclude later */
