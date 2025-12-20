#include "./ScalarConverter.hpp"
#include <iomanip>
#include <sstream>

int main(int ac, char ** av) {
    if (ac == 1) {
        std::cerr << "no input found" << std::endl;
        return 1;
    }

    std::string value = av[1];

    ScalarConverter::convert(value);
    return (0);
}
