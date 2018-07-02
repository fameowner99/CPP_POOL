#include <iostream>

void	makeUpper(int argc, char **argv)
{
	int	w;
	int	i;

	w = 1;
	while (w < argc)
	{
		i = 0;
		while (argv[w][i])
		{
			if (argv[w][i] >= 'a' && argv[w][i] <= 'z')
				std::cout << char(argv[w][i] - 32);
			else
				std::cout << argv[w][i]; 
			++i;
		}
		++w;
	}
	std::cout << std::endl;
}

int		main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
		makeUpper(argc, argv);
	return (0);
}
