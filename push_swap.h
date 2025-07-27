/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 15:17:13 by mlima-si          #+#    #+#             */
/*   Updated: 2025/07/27 16:15:12 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "./Libft/libft.h"
#include <stdio.h>
#include <limits.h>

typedef struct	s_stack
{
	int		n;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

//-----------------main-----------------
int			main(int argc, char **argv);
void		build_stack(t_stack **a, char **argv, int flag_argc);
void		free_arg(char **argv);

//-----------------errors-----------------
void		error_free(t_stack	**a, char **argv, int flag_argc);
void		free_stack(t_stack *stack);

//-----------------utils-----------------
int			stack_len(t_stack *a);
void		print_nodes(t_stack *a);
t_stack		*ft_find_last(t_stack *lst);
int			stack_sorted(t_stack *a);

//--------------push_comands---------------
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);

//--------------swap_comands---------------
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

//--------------rotate_comands---------------
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);

//----------reverse_rorate_comands-----------
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

#endif
