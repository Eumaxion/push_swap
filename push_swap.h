#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "./Libft/libft.h"
#include <stdio.h>
#include <limits.h>

typedef struct	s_stack
{
	int		n;
	void	*next;
}	t_stack;

int	main(int argc, char **argv);
int	is_valid(char c);

#endif
