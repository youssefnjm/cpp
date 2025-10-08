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
		std::string str = av[i];
		for (size_t j = 0; j < str.length(); j++)
			str[j] = std::toupper(str[j]);
		std::cout << str;
		i++;
	}
	std::cout << std::endl;
	return 0;
}
