#include <vector>
#include <algorithm>

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int sol = 0;
        int l = 0, r = height.size() - 1;

        while (l < r) {
            if (height[l] > height[r]) {
                sol = std::max(sol, height[r] * (r - l));
                r--;
            } else {
                sol = std::max(sol, height[l] * (r - l));
                l++;
            }
        }

        return sol;

    }
};