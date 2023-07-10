#include <vector>

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            int pivot = l + (r - l) / 2;
            if (nums[pivot] == target) return pivot;

            if (nums[l] <= nums[pivot]) {
                if (nums[l] <= target && target < nums[pivot]) r = pivot - 1;
                else l = pivot + 1;
            } else {
                if (nums[l] > target && target > nums[pivot]) l = pivot + 1;
                else r = pivot - 1;
            }
        }
        return -1;
    }
};