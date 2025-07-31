#include "push_swap.h"

static void	smallest_top(t_stack **a)
{
	while ((*a)->n != ft_find_smallest(*a)->n)
	{
		if (ft_find_smallest(*a)->above_middle)
			ra(a, 1);
		else
			rra(a, 1);
	}
}

void	sort_three(t_stack **stack)
{
	t_stack *biggest;
	biggest = ft_find_biggest(*stack);
	if (*stack == biggest)
		ra(stack, 1);
	else if ((*stack)->next == biggest)
		rra(stack, 1);
	if((*stack)->n > (*stack)->next->n)
		sa(stack, 1);
}
void	push_swap(t_stack **a, t_stack **b)
{
	int len_stack_a;

	len_stack_a = stack_len(*a);
	if (len_stack_a-- > 3 && !stack_sorted(*a))
		pb(a, b, 1);
	if (len_stack_a-- > 3 && !stack_sorted(*a))
		pb(a, b, 1);
	while (len_stack_a-- > 3 && !stack_sorted(*a))
	{
		init_nodes_a(*a, *b);
		a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		b_to_a(a, b);
	}
	set_index(*a);
	smallest_top(a);
}

