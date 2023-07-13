#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<std::vector<int>> res;
        
        res.push_back({});

        for (auto n: nums) {
            int k = res.size();
            for (int i = 0; i < k; i++) {
                auto temp = res[i];
                temp.push_back(n);
                res.push_back(std::move(temp));
            }
        }
        return res;
    }   
};