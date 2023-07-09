#include <vector>


class Solution {
public:
    bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) {
        if (numCourses == 1) return true;

        std::vector<bool> visited (numCourses, false);
        std::vector<bool> visiting (numCourses, false);
        std::vector<std::vector<int>> adj_list (numCourses);

        for (auto p: prerequisites) {
            adj_list[p[0]].push_back(p[1]);
        }

        for (int a = 0; a < numCourses; a++) {
            if (!visited[a] && !dfs(a, adj_list, visited, visiting)) {
                return false;
            }
        }
        return true;
    }

    bool dfs(int a,
            std::vector<std::vector<int>> &adj_list,
            std::vector<bool> &visited, 
            std::vector<bool> &visiting) {
        if (visited[a]) return true;
        if (visiting[a]) return false;
        visiting[a] = true;
        
        for (auto b: adj_list[a]) {
            if (!dfs(b, adj_list, visited, visiting)) return false;
        }

        visited[a] = true;
        return true;
    }
};