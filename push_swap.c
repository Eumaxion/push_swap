#include "push_swap.h"

void	sort_three(t_stack **stack)
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
void	push_swap(t_stack **a, t_stack **b)
{
	int len_stack_a;

	len_stack_a = stack_len(*a);
	if (len_stack_a-- > 3 && !stack_sorted(*a))
		pb(*a, *b, false);
	if (len_stack_a-- > 3 && !stack_sorted(*a))
		pb(*a, *b, false);
	while (len_stack_a-- > 3 &&!stack_sorted(*a))
	{
		init_nodes_a(*a, *b);
		a_to_b(a, b);
	}
	sort_three(*a);
	while (*b)
	{
		nodes_b(*a, *b);
		b_to_a(a, b);
	}
	while ();

}
