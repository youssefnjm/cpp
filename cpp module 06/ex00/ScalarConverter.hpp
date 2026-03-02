#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <iostream>

class ScalarConverter
{
    private:
        ScalarConverter(void);
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter &operator=(const ScalarConverter &other);
        ~ScalarConverter();

    public:
        static void convert(std::string value);
};

#endif

