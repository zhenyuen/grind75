#include <vector>
#include <unordered_map>

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
    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
        if (inorder.size() == 0) return nullptr;

        std::unordered_map<int, int> pos (inorder.size());
        for (int i = 0; i < inorder.size(); i++) pos[inorder[i]] = i;

        int curr = 0;

        auto dfs = [&] (int l, int r, auto && dfs) -> TreeNode * {
            if (l > r) return nullptr;

            auto root = preorder[curr];
            curr++;

            TreeNode* node = new TreeNode(root);
            auto m = pos[root];

            
            node -> left = dfs(l, m - 1, dfs);
            node -> right = dfs(m + 1, r, dfs);
            return node;
        };

        return dfs(0, inorder.size() - 1, dfs);
    }
};
        