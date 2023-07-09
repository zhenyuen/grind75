#include <stack>
#include <string>

class Solution {
public:
    int evalRPN(std::vector<std::string>& tokens) {
        std::stack<int> s;
        
        for (auto t: tokens) {
            if (t == "+") {
                auto a = s.top(); s.pop();
                auto b = s.top(); s.pop();
                s.push(b + a);
            } else if (t == "-") {
                auto a = s.top(); s.pop();
                auto b = s.top(); s.pop();
                s.push(b - a);
            } else if (t == "*") {
                auto a = s.top(); s.pop();
                auto b = s.top(); s.pop();
                s.push(b * a);
            } else if (t == "/") {
                auto a = s.top(); s.pop();
                auto b = s.top(); s.pop();
                s.push(b / a);
            } else {
                s.push(std::stoi(t));
            }
        }
        return s.top();
    }
};