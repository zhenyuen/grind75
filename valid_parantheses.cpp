#include <string>
#include <stack>

class Solution {
public:
    bool isValid(const std::string& s) {
        std::stack<char> stack;

        for (const auto& c: s) {
            if (stack.empty()) {
                stack.push(c);
            } else if (stack.top() == '(' && c == ')') {
                stack.pop();
            } else if (stack.top() == '{' && c == '}') {
                stack.pop();
            } else if (stack.top() == '[' && c == ']') {
                stack.pop();
            } else {
                stack.push(c);
            }
        }

        return stack.empty();
    }
};