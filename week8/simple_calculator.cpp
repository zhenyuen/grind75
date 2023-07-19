#include <stack>
// #include <ctype.h>
#include <string>

class Solution {
public:
    int calculate(std::string s) {
        std::stack<int> stack;

        int operand = 0;
        int result = 0;
        int sign = 1;

        for (auto c: s) {
            if (c == ' ') continue;
            if (std::isdigit(c)) {
                operand = (operand * 10) + int(c - '0');
            } else if (c == '+') {
                result += sign * operand;
                sign = 1;
                operand = 0;
            } else if (c == '-') {
                result += sign * operand;
                sign = -1;
                operand = 0;
            } else if (c == '(') {
                stack.push(result);
                stack.push(sign);
                sign = 1;
                result = 0;
            } else if (c == ')') {
                result += sign * operand;
                result *= stack.top(); stack.pop();
                result += stack.top(); stack.pop();
                operand = 0;
            }
            
        }
        return result + sign * operand;
    }
};