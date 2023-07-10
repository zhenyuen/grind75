#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

class Solution {
public:
    std::vector<std::vector<std::string>> accountsMerge(std::vector<std::vector<std::string>>& accounts) {
        std::unordered_map<std::string, std::unordered_set<std::string>> adj;
        std::unordered_map<std::string, bool> visited;
        std::vector<std::vector<std::string>> sol;

        for (auto a: accounts) {
            for (int i = 2; i < a.size(); i++) {
                adj[a[1]].insert(a[i]);
                adj[a[i]].insert(a[1]);
            }
        }

        auto dfs = [&](
            std::string &str, 
            std::vector<std::string> &curr,
            auto && dfs
        ) {
            if (visited.find(str) != visited.end()) return;
            visited[str] = true;
            curr.push_back(str);
            for (auto a : adj[str]) {
                dfs(a, curr, dfs);
            }
            return;
        };

        for (auto a: accounts) {
            auto root = a[1];
            if (visited.find(a[1]) != visited.end()) continue;
            
            std::vector<std::string> curr;
            dfs(root, curr, dfs);
            std::vector<std::string> temp (curr.size() + 1);
            temp[0] = a[0];

            std::partial_sort_copy(
                curr.begin(),
                curr.end(),
                temp.begin() + 1,
                temp.end()
            );

            sol.push_back(std::move(temp));
        }

        return sol;
    }
};