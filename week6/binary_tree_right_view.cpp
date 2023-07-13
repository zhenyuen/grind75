#include <vector>
#include <queue>

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
    std::vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) return {};

        std::queue<TreeNode*> q;
        std::vector<int> sol;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();
            sol.push_back(q.front() -> val);

            for (int i = 0; i < n; i++) {
                auto node = q.front(); q.pop();
                if (node -> right) q.push(node -> right);
                if (node -> left) q.push(node -> left);
            }
        }

        return sol;
    }
};