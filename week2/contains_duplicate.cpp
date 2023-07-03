#include <unordered_set>

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.size() == 1) return false;

        std::unordered_set<int> set;
        for (auto n: nums) {
            if (set.find(n) != set.end()) return true;
            set.insert(n);
        }
        return false;
    }
};