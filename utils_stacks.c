#include"push_swap.h"

void	a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = find_cheapest(*a);
	if (cheapest_node->above_middle && cheapest_node->target->above_middle)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_middle) && !(cheapest_node->target->above_middle))
		rev_rotate_both(a, b, cheapest_node);
	set_for_push(a, cheapest_node, 'a');
	set_for_push(b, cheapest_node->target, 'b');
	pb(a, b, 1);
}
void	set_for_push(t_stack **stack, t_stack *first_node, char	name)
{
	while(*stack != first_node)
	{
		if (name == 'a')
		{
			if (first_node->above_middle)
				ra(stack, 1);
			else
				rra(stack, 1);
		}
		else if (name == 'b')
		{
			if (first_node->above_middle)
				rb(stack, 1);
			else
				rrb(stack, 1);
		}
	}
}
void	b_to_a(t_stack **a, t_stack **b)
{
	set_for_push(a, (*b)->target, 'a');
	pa(a, b, 1);
}
