#ifndef RPN_HPP
# define RPN_HPP
# include <iostream>

class RPN
{
    private:
        bool isInputValid(char c);
        int applyOperator(char opr, int num1, int num2);

    public:
        RPN(void);
        RPN(const RPN& other);
        RPN &operator=(const RPN &other);
        ~RPN();

        void calculate(std::string input);
};

#endif

