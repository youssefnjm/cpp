#include "RPN.hpp"
#include <iostream>
#include <sstream>
#include <stack>
#include <stdexcept>

RPN::RPN(void) {}
RPN::RPN(const RPN &other) { (void) other; }
RPN &RPN::operator=(const RPN &other) { (void) other; return (*this); }
RPN::~RPN(void) {}

bool isInputValid(char c) {
    return (!(c >= '0' && c <= '9') 
        && !(c == '+' || c == '-' || c == '*' || c == '/'));
};

void RPN::calculate(std::string input)
{
    std::stack<int> stack;

    std::stringstream ss(input);
    std::string buffer;
    while (ss >> buffer) {

        if (buffer.length() != 1 || isInputValid(buffer[0]))
            throw std::runtime_error("Error: argument should be operator (+ - / *) or numbers less than 10.");

        if (buffer[0] >= '0' && buffer[0] <= '9') {
            stack.push(std::atoi(buffer.c_str()));
            continue ;
        }

        if (stack.size() < 2) {
            throw std::runtime_error("Error: Invalid expression (too many operators left over).");
        }

        int num1 = stack.top();
        stack.pop();
        int num2 = stack.top();
        stack.pop();

        int res;
        if (buffer[0] == '+') {
            res = num2 + num1;
        } 
        else if (buffer[0] == '-') {
            res = num2 - num1;
        } 
        else if (buffer[0] == '*') {
            res = num2 * num1;
        } 
        else {
            if (num1 == 0)
                throw std::runtime_error("Error: can't div by 0");

            res = num2 / num1;
        }

        stack.push(res);
    }


    if (stack.size() != 1)
        throw std::runtime_error("Error: Invalid expression (too many numbers left over).");
    std::cout << stack.top() << std::endl;
}
