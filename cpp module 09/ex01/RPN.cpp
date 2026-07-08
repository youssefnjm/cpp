#include "RPN.hpp"
#include <iostream>
#include <sstream>
#include <stack>
#include <stdexcept>

RPN::RPN(void) {};
RPN::RPN(const RPN &other) { (void) other; };
RPN &RPN::operator=(const RPN &other) { (void) other; return (*this); };
RPN::~RPN(void) {};

bool RPN::isInputValid(std::string buffer) {
    if (buffer.length() != 1)
        return false;
    char c = buffer[0];
    if (!std::isdigit(c) && !(c == '+' || c == '-' || c == '*' || c == '/'))
        return false;
    return true;
};

double RPN::applyOperator(char opr, double num1, double num2) {
    if (opr == '+') return (num2 + num1);
    if (opr == '-') return (num2 - num1);
    if (opr == '*') return (num2 * num1);
    if (num1 == 0) throw std::runtime_error("Error: can't div by 0");
    return (num2 / num1);                
};

void RPN::calculate(std::string input) {
    std::stack<double> stack;

    std::stringstream ss(input);
    std::string buffer;
    while (ss >> buffer) {
        if (!isInputValid(buffer))
            throw std::runtime_error("Error: argument should be operator (+ - / *) or numbers less than 10.");

        if (std::isdigit(buffer[0])) {
            stack.push(std::atoi(buffer.c_str()));
            continue ;
        }

        if (stack.size() < 2)
            throw std::runtime_error("Error: Invalid expression (too many operators left over).");

        double num1 = stack.top();
        stack.pop();
        double num2 = stack.top();
        stack.pop();

        double res = applyOperator(buffer[0], num1, num2);
        stack.push(res);
    }

    if (stack.size() == 0)
        throw std::runtime_error("Error: argument is empty.");

    if (stack.size() != 1)
        throw std::runtime_error("Error: Invalid expression (too many numbers left over).");

    std::cout << stack.top() << std::endl;
};
