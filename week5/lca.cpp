/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    //     bool found = false;
    //     TreeNode* target = nullptr;

    //     auto dfs = [&] (TreeNode* root, auto &&dfs) {
    //         if (found) return false;
    //         if (root == nullptr) return false;
            
    //         auto left = dfs(root -> left, dfs);
    //         auto right = dfs(root -> right, dfs);
    //         auto mid = (root == p) || (root == q);

    //         if (left + right + mid >= 2) {
    //             found = true;
    //             target = root;
    //         }
            
    //         return mid || left || right;
    //     };

    //     dfs(root, dfs);
    //     return target;
    // }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return nullptr;
        // nullptr means LCA does not exist
        if (root == p || root == q) return root;

        auto l = lowestCommonAncestor(root -> left, p, q);
        auto r = lowestCommonAncestor(root -> right, p, q);
        if (l && r) return root;
        if (l) return l;
        if (r) return r;
        return nullptr;
    }
};