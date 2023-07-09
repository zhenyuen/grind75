#include <limits>
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
    bool isValidBST(TreeNode* root) {
        return dfs(root, std::numeric_limits<long>::min(), std::numeric_limits<long>::max());
    }

    bool dfs(TreeNode* root, long low, long high) {
        if (!root) return true;

        int curr = root -> val;
        if (curr <= low || curr >= high) return false;

        return dfs(root -> left, low, curr) && 
            dfs(root -> right, curr, high);
    }
};