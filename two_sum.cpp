#include <unordered_map>
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> indices;
        
        for (int i = 0; i < nums.size(); i++) {
            auto n = nums[i];
            auto diff = target - n;
            if (indices.find(diff) == indices.end()) {
                indices[diff] = i;
            } else {
                return {indices[diff], i};            
            }
        }
        return {-1};
    }
};