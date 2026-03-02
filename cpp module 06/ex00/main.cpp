#include "./ScalarConverter.hpp"

int main(int ac, char ** av) {
    if (ac == 1) {
        std::cerr << "no input found\n";
        return 1;
    }

    std::string value = av[1];

    ScalarConverter::convert(value);

    return (0);
}
