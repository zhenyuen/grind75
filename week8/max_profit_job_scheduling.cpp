#include <vector>

class Solution {
public:
    // int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
    //     std::unordered_map<int, int> cache;
    //     int max_profit = 0;
    //     int n = startTime.size();

    //     std::vector<std::vector<int>> jobs;

    //     for (int i = 0; i < n; i++) {
    //         jobs.push_back({startTime[i], endTime[i], profit[i]});
    //     }

    //     std::sort(jobs.begin(), jobs.end());

    //     for (int i = 0; i < n; i++) {
    //         startTime[i] = jobs[i][0];
    //     }

    //     auto dfs = [&] (auto &&dfs, int i) {
    //         if (i == n) return 0;

    //         if (cache.find(i) != cache.end()) return cache[i];

    //         int next_pos = std::lower_bound(startTime.begin(), startTime.end(), jobs[i][1]) - startTime.begin();

    //         int max_profit = std::max(dfs(dfs, i + 1), jobs[i][2] + dfs(dfs, next_pos));
    
    //         return cache[i] = max_profit;
    //     };

    //     return dfs(dfs, 0);
    // }

    int jobScheduling(std::vector<int>& startTime, std::vector<int>& endTime, std::vector<int>& profit) {
        int dp[50001];
        int n = startTime.size();

        std::vector<std::vector<int>> jobs;

        for (int i = 0; i < n; i++) {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }

        std::sort(jobs.begin(), jobs.end());

        for (int i = 0; i < n; i++) {
            startTime[i] = jobs[i][0];
        }

        dp[n - 1] = jobs[n - 1][2];
        for (int i = n - 2; i >= 0; i--) {
            int profit = 0;
            int next_pos = std::lower_bound(startTime.begin(), startTime.end(), jobs[i][1]) - startTime.begin();

            profit = jobs[i][2];

            if (next_pos < n) profit += dp[next_pos];

            dp[i] = std::max(profit, dp[i + 1]);
        }

        return dp[0];
    }
};