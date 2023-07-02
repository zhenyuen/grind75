#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> floodFill(const std::vector<std::vector<int>>& image, const int sr, const int sc, const int color) {
        auto edited = image;
        auto s_color = edited[sr][sc];

        fill(edited, sr, sc, color, s_color);

        return edited;
    }

    void fill(std::vector<std::vector<int>>& image, const int i, const int j, const int color, const int s_color) {
        if (image[i][j] == color) return;

        image[i][j] = color;

        if (i < image.size() - 1 && image[i+1][j] == s_color) fill(image, i + 1, j, color, s_color);
        if (i > 0 && image[i-1][j] == s_color) fill (image, i - 1, j, color, s_color);
        if (j < image[i].size() - 1 && image[i][j+1] == s_color) fill(image, i, j + 1, color, s_color);
        if (j > 0 && image[i][j-1] == s_color) fill (image, i, j - 1, color, s_color);
    }
};

class Solution {
static constexpr int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

public:
    std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>>& image, const int sr, const int sc, const int color) {
        if (image[sr][sc] == color) return image;

        auto s_color = image[sr][sc];

        for (auto const &d: dir) {
            auto new_r = sr + d[0];
            auto new_c = sc + d[1];
            if (0 <= new_r &&
                new_r < image.size() &&
                0 <= new_c &&
                new_c < image[new_r].size() &&
                image[new_r][new_c] == s_color) {
                    return floodFill(image, new_r, new_c, color);
                }
        }
        return image;
    }
};

class Solution {
static constexpr int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

public:
    std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>>& image, const int sr, const int sc, const int color) {
        if (image[sr][sc] == color) return image;

        int s_color = image[sr][sc];
        image[sr][sc] = color;

        int new_r, new_c;
        for (auto const &d: dir) {
            new_r = sr + d[0];
            new_c = sc + d[1];
            if (0 <= new_r &&
                new_r < image.size() &&
                0 <= new_c &&
                new_c < image[new_r].size() &&
                image[new_r][new_c] == s_color) {
                    floodFill(image, new_r, new_c, color);
                }
        }
        return image;
    }
};

class Solution {
static constexpr int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

public:
    std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>>& image, const int sr, const int sc, const int color) {
        if (image[sr][sc] == color) return image;

        int s_color = image[sr][sc];
        image[sr][sc] = color;

        int new_r, new_c;
        for (auto const &d: dir) {
            new_r = sr + d[0];
            new_c = sc + d[1];
            if (0 <= new_r &&
                new_r < image.size() &&
                0 <= new_c &&
                new_c < image[new_r].size() &&
                image[new_r][new_c] == s_color) {
                    floodFill(image, new_r, new_c, color);
                }
        }
        return image;
    }
};