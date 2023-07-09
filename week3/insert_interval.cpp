#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals, std::vector<int>& newInterval) {
        std::vector<std::vector<int>> sol;
        
        int i = 0, n = intervals.size();
        while (i < n and intervals[i][1] < newInterval[0]) {
            sol.push_back(intervals[i]);
            i++;
        }

        auto merged = newInterval;

        while (i < n and intervals[i][0] <= merged[1]) {
            merged[0] = std::min(merged[0], intervals[i][0]);
            merged[1] = std::max(merged[1], intervals[i][1]);
            i++;
        }

        sol.push_back(merged);

        while (i < n) {
            sol.push_back(intervals[i]);
            i++;
        }

        return sol;
    }
};