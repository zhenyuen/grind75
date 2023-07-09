#include <queue>

class Solution {
public:
    int orangesRotting(std::vector<std::vector<int>>& grid) {
        int minutes = 0;
        int m = grid.size();
        int n = grid[0].size();
        int n_fresh_oranges = 0;
        std::queue<std::pair<int, int>> v;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) v.push({i, j});
                if (grid[i][j] == 1) n_fresh_oranges++;
            }
        }

        while (!v.empty()) {
            int has_rot = false;
            int k = v.size();
            for (int i = 0; i < k; i++) {
                auto [r, c] = v.front(); v.pop();
        
                if (r > 0 && (grid[r - 1][c] == 1)) {
                    grid[r - 1][c] = 2;
                    v.push({r - 1, c});
                    n_fresh_oranges--;
                    has_rot = true;
                }
                if (c > 0 && (grid[r][c - 1] == 1)) {
                    grid[r][c - 1] = 2;
                    v.push({r, c - 1});
                    n_fresh_oranges--;
                    has_rot = true;
                }
                if (r < m - 1 && (grid[r + 1][c] == 1)) {
                    grid[r + 1][c] = 2;
                    v.push({r + 1, c});
                    n_fresh_oranges--;
                    has_rot = true;
                }
                if (c < n - 1 && (grid[r][c + 1] == 1)) {
                    grid[r][c + 1] = 2;
                    v.push({r, c + 1});
                    n_fresh_oranges--;
                    has_rot = true;
                }
            }
            if (has_rot) minutes++;
        }
        return n_fresh_oranges == 0? minutes : -1;
    }
};