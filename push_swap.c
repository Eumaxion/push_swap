#include "push_swap.h"

int	is_valid(char *nbr)
{
	int	i;

	i = 0;
	if (nbr[i] == '+' || nbr[i] == '-')
		i++;
	while(ft_isdigit(nbr[i]))
		i++;
	if (!nbr[i])
		return(0);
	return (1);
}
int	error_free(t_stack	*a, char **argv, int flag_argc)
{
	if (flag_argc)
		free(argv);
	if (a == NULL)
		return (0);
}
int check_repeated(t_stack	*a, int n)
{
	
}

void	add_node(t_stack *a, int)
{

}
void	build_stack(t_stack **a, char **argv, int flag_argc)
{
	long	n;
	int		i;

	i = 1;
	while (argv[i])
	{
		if (!is_valid(argv[i]))
			error_free(a, &argv, flag_argc);
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			error_free(a, &argv, flag_argc);
		if (check_repeated(a, n))
			error_free(a, &argv, flag_argc);
		add_node(a, n);
	}
	if (flag_argc)
		free(argv);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if(argc < 2 || argc == 2 && !argv[1][0])
	{
		write(1, "Error\n", 7);
		return(0);	
	}
	if (argc == 2)
		argv = ft_split(argv[1], 32);
	build_stack(a, argv, argc == 2);
	return (0);
}

