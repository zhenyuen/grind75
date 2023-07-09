#include <stack>
#include <vector>

class Solution {
public:
    int numIslands(std::vector<std::vector<char>>& grid) {
        std::stack<std::pair<int, int>> s;
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != '1') continue;

                ans++;
                s.push({i, j});
                grid[i][j] == '#';

                while (!s.empty()) {
                    auto [r, c] = s.top(); s.pop();

                    if (r > 0 && grid[r - 1][c] == '1') {
                        grid[r - 1][c] = '#';
                        s.push({r - 1, c});
                    }
                    if (c > 0 && grid[r][c - 1] == '1') {
                        grid[r][c - 1] = '#';
                        s.push({r, c - 1});
                    }
                    if (r < m - 1 && grid[r + 1][c] == '1') {
                        grid[r + 1][c] = '#';
                        s.push({r + 1, c});
                    }
                    if (c < n - 1 && grid[r][c + 1] == '1') {
                        grid[r][c + 1] = '#';
                        s.push({r, c + 1});
                    }
                }
            }
        }
        return ans;
    }
};