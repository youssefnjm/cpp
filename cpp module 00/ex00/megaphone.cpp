#include <iostream>
#include <cctype>

int main(int ac, char **av)
{
	int i = 1;
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	while (i < ac)
	{
		int j = -1;
		while (av[i][++j] != '\0')
			av[i][j] = toupper(av[i][j]);
		std::cout << av[i]; 
		i++;
	}
	std::cout << std::endl; 
	return 0;
}
