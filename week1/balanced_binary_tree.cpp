#include <utility>
#include <algorithm>
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
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;

        return abs(height(root -> left) - height(root -> right)) < 2;

    }

    std::pair<bool, int> height(TreeNode* root) {
        if (root == nullptr) return {true, 0};

        auto [left_is_balanced, left_height] = height(root -> left);
        auto [right_is_balanced, right_height] = height(root -> right);
        
        return {left_is_balanced and right_is_balanced,
            std::max(left_height, right_height) + 1
        }
    }
};