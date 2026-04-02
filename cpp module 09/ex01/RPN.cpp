#include "RPN.hpp"
#include <iostream>
#include <sstream>
#include <stack>

RPN::RPN(void) {}
RPN::RPN(const RPN &other) { (void) other; }
RPN &RPN::operator=(const RPN &other) { (void) other; return (*this); }
RPN::~RPN(void) {}

void RPN::calculate(std::string input)
{
    std::stringstream ss(input);
    std::stack<int> stack;

    std::string buffer;
    while (ss >> buffer) {
        if (buffer.length() != 1) {
            std::cerr << "Error: argument should be less than 10\n";
            return ;
        }

        if (!(buffer[0] >= '0' && buffer[0] <= '9')
            && !(buffer[0] == '+' || buffer[0] == '-' || buffer[0] == '*' || buffer[0] == '/'))
        {
            std::cerr << "Error: argument should be numbers or operator '+ - / *'\n";
            return ;
        }

        if (buffer[0] >= '0' && buffer[0] <= '9') {
            stack.push(std::atoi(buffer.c_str()));
        }
        else
        {
            if (stack.size() < 2) {
                std::cerr << "Error: not enough numbers compared to number of operators\n";
                return;
            }
            int num1 = stack.top();
            stack.pop();
            int num2 = stack.top();
            stack.pop();

            if (buffer[0] == '+') {
                stack.push(num2 + num1);
            } else if (buffer[0] == '-') {
                stack.push(num2 - num1);
            } else if (buffer[0] == '*') {
                stack.push(num2 * num1);
            } else {
                if (num1 == 0) {
                    std::cerr << "Error: can't div by 0\n";
                    return;
                }
                stack.push(num2 / num1);
            }
        }
    }
    std::cout << stack.top() << std::endl;
}
