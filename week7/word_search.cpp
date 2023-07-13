#include <vector>
#include <string>

class Solution {
public:
    
    bool exist(std::vector<std::vector<char>>& board, std::string word) {
        int m = board.size();
        int n = board[0].size();
        std::vector<std::pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        auto dfs = [&] (int i, int j, int k, auto && dfs) {
            if (k == word.size()) {
                return true;
            }
            if (!((0 <= i && i < m && 0 <= j && j < n))) return false;
            if (board[i][j] != word[k]) return false;

            char temp = board[i][j];
            board[i][j] = '#';

            for (auto d: dir) {
                auto r = d.first + i;
                auto c = d.second + j;
                if (dfs(r, c, k + 1, dfs)) return true;
            }
            board[i][j] = temp;
            
            return false;
        };

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0] && dfs(i, j, 0, dfs)) {
                    return true;
                }
            }
        }
        return false;
    }
};