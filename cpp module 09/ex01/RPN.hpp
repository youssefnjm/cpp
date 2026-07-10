#ifndef RPN_HPP
# define RPN_HPP
# include <iostream>

class RPN
{
    private:
        bool isOperator(std::string buffer);
        double applyOperator(char opr, double num1, double num2);
        bool isNumber(const std::string &buffer);

    public:
        RPN(void);
        RPN(const RPN& other);
        RPN &operator=(const RPN &other);
        ~RPN();

        void calculate(std::string input);
};

#endif

