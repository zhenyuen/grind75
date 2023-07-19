#include <stack>

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
    TreeNode* node; 
    int i;

    int kthSmallest(TreeNode* root, int k) {
        dfs(root, k);
        return node -> val;
    }

    void dfs(TreeNode* root, int k) {
        if (root == nullptr) return;

        dfs(root -> left, k);

        if (k == i) return;
        node = root;
        i++;

        dfs(root -> right, k);
    }
};