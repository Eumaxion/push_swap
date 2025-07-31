/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 15:17:13 by mlima-si          #+#    #+#             */
/*   Updated: 2025/07/31 16:54:02 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "./Libft/libft.h"
#include <stdio.h>
#include <limits.h>

typedef struct	s_stack
{
	int				n;
	int				index;
	int				above_middle;
	int				p_cost;
	int				cheapest;
	struct s_stack	*target;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

//-----------------main-----------------
int			main(int argc, char **argv);
void		print_nodes(t_stack *a);
void		build_stack(t_stack **a, char **argv, int flag_argc);
void		push_swap(t_stack **a, t_stack **b);

//-----------------errors-----------------
void		error_free(t_stack	**a, char **argv, int flag_argc);
void		free_stack(t_stack *stack);
void		free_arg(char **argv);

//----------------node utils---------------
int			stack_len(t_stack *a);
int			stack_sorted(t_stack *a);
t_stack		*ft_find_last(t_stack *lst);
t_stack 	*ft_find_biggest(t_stack *stack);
t_stack		*ft_find_smallest(t_stack *stack);
t_stack		*find_cheapest(t_stack *stack);

//----------------stack utils---------------
void		set_index(t_stack *stack);
void		set_price(t_stack *a, t_stack *b);
void		set_cheapest(t_stack *stack);
void		set_for_push(t_stack **stack, t_stack *first_node, char	name);
void		init_nodes_a(t_stack *a, t_stack *b);
void		init_nodes_b(t_stack *a, t_stack *b);
void		a_to_b(t_stack **a, t_stack **b);
void		b_to_a(t_stack **a, t_stack **b);
void		target_in_a(t_stack *a, t_stack *b);
void		target_in_b(t_stack *a, t_stack *b);

//----------------push_swap ----------------
void		push_swap(t_stack **a, t_stack **b);
void		sort_three(t_stack **stack);

//--------------push_comands---------------
void		pa(t_stack **a, t_stack **b, int print);
void		pb(t_stack **a, t_stack **b, int print);

//--------------swap_comands---------------
void		sa(t_stack **a, int print);
void		sb(t_stack **b, int print);
void		ss(t_stack **a, t_stack **b, int print);

//--------------rotate_comands---------------
void		ra(t_stack **a, int print);
void		rb(t_stack **b, int print);
void		rr(t_stack **a, t_stack **b, int print);
void		rotate_both(t_stack **a, t_stack **b, t_stack *cheapest);

//----------reverse_rorate_comands-----------
void		rra(t_stack **a, int print);
void		rrb(t_stack **b, int print);
void		rrr(t_stack **a, t_stack **b, int print);
void		rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest);

#endif
