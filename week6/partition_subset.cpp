#include <vector>

class Solution {
public:
    bool canPartition(std::vector<int>& nums) {
        int m = 0;
        for (auto n: nums) m += n;

        if (m % 2 == 1) return false;

        int k = m / 2;
        int l = nums.size();
        std::vector<std::vector<bool>> dp(l + 1, std::vector<bool>(k + 1));
        
        for (int i = 1; i <= k; i++) dp[0][i] = false;
        for (int i = 0; i <= l; i++) dp[i][0] = true; 

        for (int i = 1; i <= l; i++) {
            for (int j = 1; j <= k; j++) { // target sum
                auto curr_e = nums[i - 1];
                if (curr_e > j) {
                    // Do not include current element, as adding it yields
                    // invalid answer
                    dp[i][j] = dp[i - 1][j];
                } else {
                    // include or dont include curr element.
                    dp[i][j] = dp[i - 1][j - curr_e] || dp[i - 1][j];
                }
            }
        }
        // dependency on only the previous row, i.e., dp[i - 1]
        // indicates an O(n) solution is possible.
 
        return dp[l][k];
    }
};