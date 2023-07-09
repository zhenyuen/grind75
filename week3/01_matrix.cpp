#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> updateMatrix(std::vector<std::vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        std::vector<std::vector<int>> copy (m, std::vector<int>(n, INT_MAX - 1));

    
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    copy[i][j] = 0;
                    continue;
                }
                if (i > 0) copy[i][j] = std::min(copy[i][j], copy[i-1][j] + 1);
                if (j > 0) copy[i][j] = std::min(copy[i][j], copy[i][j-1] + 1);
            }
        }

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i < m - 1) {
                    copy[i][j] = std::min(copy[i][j], copy[i+1][j] + 1);
                }
                
                if (j < n -1) {
                    copy[i][j] = std::min(copy[i][j], copy[i][j+1] + 1);
                }
                
            }
        }
        return copy;
    }
};