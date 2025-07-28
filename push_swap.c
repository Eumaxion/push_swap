#include "push_swap.h"

t_stack *ft_find_biggest(t_stack *stack)
{
	t_stack *biggest;

	biggest = stack;
	stack = stack->next;
	while(stack)
	{
		if (biggest->n < stack->n)
			biggest = stack;
		stack = stack->next;
	}
	return(biggest);
}
void	fast_sort(t_stack **stack)
{
	t_stack *biggest;
	biggest = ft_find_biggest(*stack);
	if (*stack == biggest)
		ra(stack);
	else if ((*stack)->next == biggest)
		rra(stack);
	if((*stack)->n > (*stack)->next->n)
		sa(stack);
}
void	push_swap(void)
{
	write(1,"swaaaaaap\n", 11);
}

//t_stack **a, t_stack **b