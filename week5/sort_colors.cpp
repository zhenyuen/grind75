#include <vector>

class Solution {
public:
    void sortColors(std::vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        int curr = 0;


        while (curr <= r) {
            if (nums[curr] == 2) {
                std::swap(nums[curr], nums[r]);
                r--;
            } else if (nums[curr] == 0) {
                std::swap(nums[curr], nums[l]);
                l++; curr++;
            } else {
                curr++;
            }
        }
    }
};