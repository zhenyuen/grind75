#include <vector>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        return dfs(root).second;
    }

    std::pair<int, int> dfs(TreeNode* root) {
        if (root == nullptr) return {-1, -1};

        auto [l_long ,l_dia] = dfs(root -> left);
        auto [r_long, r_dia] = dfs(root -> right);
        return {
            std::max(l_long, r_long) + 1,
            std::max({l_long + r_long + 2, l_dia, r_dia})
        };
    }
};