#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int max_profit = 0;
        int buy_price = prices[0];

        for (int i = 1; i < prices.size(); i++) {
            if (buy_price > prices[i]) {
                buy_price = prices[i];
            } else {
                max_profit = std::max(max_profit, prices[i] - buy_price);
            }
        }

        return max_profit;
    }
};
