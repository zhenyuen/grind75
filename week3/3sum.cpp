#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<std::vector<int>> sol;
        std::sort(nums.begin(), nums.end());

        for (int k = 0; k < n && nums[k] <= 0;) {
            int l = k + 1, r = n - 1;
            int target = -nums[k];

            while (l < r) {
                int sum = nums[l] + nums[r];
                if (sum > target) {
                    r--;
                } else if (sum < target) {
                    l++;
                } else {
                    sol.push_back({nums[k], nums[l], nums[r]});
                    l++;
                    while (l < r && (nums[l - 1] == nums[l])) l++;
                }
            }
            k++;
            while (k < n && (nums[k - 1] == nums[k])) k++;
        }
        return sol;
    }
};