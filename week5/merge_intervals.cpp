#include <vector>

class Solution {
public:
    // vector<vector<int>> merge(vector<vector<int>>& intervals) {
    //     std::sort(intervals.begin(), intervals.end());

    //     for (auto it = intervals.begin() + 1; it != intervals.end();) {
    //         auto prev = std::prev(it);
    //         if ((*it)[0] <= (*prev)[1]) {
    //             auto a = std::min((*prev)[0], (*it)[0]);
    //             auto b = std::max((*prev)[1], (*it)[1]);
    //             *prev = {a, b};
    //             it = intervals.erase(it);
    //             continue;
    //         }
    //         it++;
    //     }
    //     return intervals;
    // }

    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        if (intervals.size() == 1) return intervals;
        
        std::sort(intervals.begin(), intervals.end());
        std::vector<std::vector<int>> sol;
        sol.reserve(intervals.size());
        sol.push_back(intervals.front());

        for (auto it = ++intervals.begin(); it != intervals.end(); it++) {
            auto &prev = sol.back();
            auto curr = *it;
            if (curr[0] <= prev[1]) {
                auto a = std::min(prev[0], curr[0]);
                auto b = std::max(prev[1], curr[1]);
                prev = {a, b};
            } else {
                sol.push_back(curr);
            }
        }
        return sol;
    }
};