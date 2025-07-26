/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 15:17:13 by mlima-si          #+#    #+#             */
/*   Updated: 2025/07/26 16:38:19 by mlima-si         ###   ########.fr       */
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
	void	*prev;
	void	*next;
}	t_stack;

//-----------------main-----------------
int		main(int argc, char **argv);
void	build_stack(t_stack **a, char **argv, int flag_argc);
void	add_node(t_stack **a, int n);

//-----------------errors-----------------
void	error_free(t_stack	**a, char **argv, int flag_argc);
void	free_stack(t_stack *stack);

//-----------------validation-----------------
int		is_valid(char *nbr);
int		check_repeated(t_stack	*a, int n);

//-----------------utils-----------------
int		stack_len(t_stack *a);
void	print_nodes(t_stack *a);
t_stack	*ft_find_last(t_stack *lst);

//-----------------commands-----------------
void	swap(t_stack *a);

#endif
