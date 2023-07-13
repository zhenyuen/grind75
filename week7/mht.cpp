#include <vector>
#include <unordered_map>
#include <unordered_set>

class Solution {
public:
    std::vector<int> findMinHeightTrees(int n, std::vector<std::vector<int>>& edges) {
        std::unordered_map<int, std::unordered_set<int>> adj_list(n);
        std::vector<int> leaves;

        for (auto e: edges) {
            adj_list[e[0]].insert(e[1]);
            adj_list[e[1]].insert(e[0]);
        }

        for (int i = 0; i < n; i++) {
            if (adj_list[i].size() == 1) leaves.push_back(i);
        }

        while (adj_list.size() > 2) {
            std::vector<int> temp;
            int k = leaves.size();
            for (int p = 0; p < k; p++) {
                int leaf = leaves.back(); leaves.pop_back();
                int neighbour = *(adj_list[leaf].begin());
                adj_list.erase(leaf);
                adj_list[neighbour].erase(leaf);

                if (adj_list[neighbour].size() == 1) temp.push_back(neighbour);
            }
            leaves = std::move(temp);
        }

        std::vector<int> v;
        for (auto a: adj_list) v.push_back(a.first);
        return v;
    }
};