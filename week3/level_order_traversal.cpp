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
    std::vector<std::vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        
        std::vector<std::vector<int>> sol;
        std::queue<TreeNode*> q;

        q.push(root);

        while (!q.empty()) {
            std::vector<int> temp;
            int t = q.size();
            for (int i = 0; i < t; i++) {
                auto node = q.front(); q.pop();
                temp.push_back(node -> val);
                if (node -> left != nullptr) q.push(node -> left);
                if (node -> right != nullptr) q.push(node -> right);
            }
            if (!temp.empty()) sol.push_back(std::move(temp));
        }

        return sol;
    }
};