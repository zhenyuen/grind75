#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::vector<std::vector<std::vector<int>>> dp(target + 1);

        dp[0] = {{}};

        for (auto c: candidates) {
            for (int t = 1; t < dp.size(); t++) {
                if (t - c < 0) continue;
                for (auto v: dp[t - c]) {
                    v.push_back(c);
                    dp[t].push_back(v);
                }
            }
        }
        return dp[target];
    }
};