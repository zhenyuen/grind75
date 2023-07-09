#include <cmath>
#include <queue>
#include <vector>

typedef std::priority_queue<std::pair<double, int>> min_heap;

class Solution {
public: 
    std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>>& points, int k) {
        min_heap pq;
        std::vector<std::vector<int>> sol;
        
        for (int i = 0; i < points.size(); i++) {
            auto x = points[i][0];
            auto y = points[i][1];
            pq.push({-distance(x, y), i});
        }

        for (int i = 0; i < k; i++) {
            auto e = pq.top(); pq.pop();
            auto point = points[e.second];
            sol.push_back(point);
        }

        return sol;
    }

    double distance(int x, int y) {
        return std::sqrt(x * x + y * y);
    }
};