#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::vector<std::vector<int>> sol;

        auto dfs = [&] (int k, auto &&dfs) {
            if (k == nums.size() - 1) {
                sol.push_back(nums);
                return;
            }

            for (int i = k; i < nums.size(); i++) {
                std::swap(nums[k], nums[i]);
                dfs(k + 1, dfs);
                std::swap(nums[k], nums[i]); 
            }
            return;
        };

        dfs(0, dfs);
        return sol;
    }

    
};