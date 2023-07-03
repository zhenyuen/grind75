#include <vector>

class Solution {
public:
    int search(const std::vector<int>& nums, const int target) {
        int l = 0, r = nums.size() - 1;

        while (l <= r) {
            auto pivot = l + (r - l) / 2;
            auto n = nums[pivot];

            if (n < target) {
                l = pivot + 1;
            } else if (n > target) {
                r = pivot - 1;
            } else {
                return pivot;
            }
        }
        return -1;
    }
};