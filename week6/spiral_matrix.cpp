#include <vector>

class Solution {
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
        std::vector<int> sol;
        std::vector<std::pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int top = 0, bot = matrix.size() - 1;
        int left = 0, right = matrix[0].size() - 1;
        int d = 0;
        int i = 0, j = 0;

        for (int n = matrix.size() * matrix[0].size(); n > 0; n--) {
            
            if (j > right) {
                j--; i++;
                d = 1;
                top++;
            } else if (i > bot) {
                i--; j--;
                d = 2;
                right--;
            } else if (j < left) {
                j++; i--;
                d = 3;
                bot--;
            } else if (i < top) {
                i++; j++;
                d = 0;
                left++;
            }

            sol.push_back(matrix[i][j]);
            i += dir[d].first;
            j += dir[d].second;
        }

        return sol;
    }
};