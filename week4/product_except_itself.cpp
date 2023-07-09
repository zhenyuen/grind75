#include <vector>

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        if (nums.size() == 1) return nums;

        int n = nums.size();
        
        std::vector<int> post(n, nums.back());
        std::vector<int> pre(n, nums.front());
        std::vector<int> sol(n, 1);

        for (int i = 1; i < n; i++) {
            pre[i] = nums[i] * pre[i - 1];
        }

        for (int i = n - 2; i >= 0; i--) {
            post[i] = nums[i] * post[i + 1];
        }

        for (int i = 1; i < n - 1; i++) {
            sol[i] = pre[i - 1] * post[i + 1];
        }
        
        sol[0] = post[1];
        sol[n - 1] = pre[n - 2];
        return sol;
    }
};