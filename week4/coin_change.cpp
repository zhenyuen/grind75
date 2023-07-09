#include <vector>

class Solution {
public:
    int coinChange(std::vector<int>& coins, int amount) {
        std::vector<int> dp(amount + 1, amount + 1);
        
        dp[0] = 0;
    
        for (int i = 1; i < dp.size(); i++) {
            for (auto c: coins) {
                int change = i - c;
                if (change < 0) continue;
                // if (dp[change] == -1) continue; 
                dp[i] = std::min(dp[change] + 1, dp[i]);
            }
        }

        return dp[amount] != amount + 1? dp[amount] : -1;
    }
};