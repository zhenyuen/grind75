#include <vector>
#include <stack>

class Solution {
public:
    int largestRectangleArea(std::vector<int>& heights) {
        std::stack<int> s;
        s.push(-1);

        int sol = 0;

        for (int i = 0; i < heights.size(); i++) {
            while (s.top() != -1 && heights[s.top()] >= heights[i]) {
                int h = heights[s.top()];
                s.pop();
                int w = i - s.top() - 1;
                sol = std::max(sol, h * w);
            }
            s.push(i);
        }

        int n = heights.size();
        while (s.top() != -1) {
            int h = heights[s.top()];
            s.pop();
            int w = n - s.top() - 1;
            sol = std::max(sol, h * w);
        }
        return sol;
    }
};