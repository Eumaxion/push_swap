#include "push_swap.h"
#include <stdio.h>

int	is_valid(char c)
{
	if (ft_isdigit(c) || c == 32 || c == 43 || c == 45)
		return (1);
	return (0);
}
int	main(int argc, char **argv)
{
	//#argceita " " "+" "-"
	int j = 0;
	if(argc <= 2)
	{
		write(1, "Error\n", 7);
		return(0);	
	}
	if (argc > 2)
	{
		while (argc > 1)
		{
			argc--;
			j = 0;
			printf("%s\n", argv[argc]);
			while (argv[argc][j])
			{
				if(!is_valid(argv[argc][j]))
				{
					write(1, "Error\n", 7);
					return(0);	
				}
				j++;
			}
		}
		write(1, "OK\n", 4);
	}
	return (0);
}
