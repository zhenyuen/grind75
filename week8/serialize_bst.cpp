
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
};

#include <string>
#include <vector>
#include <unordered_map>

typedef std::unordered_map<TreeNode*, int> Dict;

class Codec {
   public:
    std::string inorder;
    
    Codec() {
        inorder = "";
    }

    // Encodes a tree to a single string.
    std::string serialize(TreeNode* root) {
        auto in = [&] (auto && in, TreeNode* root) {
            if (root == nullptr) {
                inorder += "N,";
                return;
            }
            inorder += (std::to_string(root -> val) + ',');
            in(in, root -> left);
            in(in, root-> right);
            return;
        };
        in(in, root);
        return inorder;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(std::string data) {
        int i = 0;
        auto dfs = [&] (auto && dfs) -> TreeNode* {
            if (i >= data.size()) return nullptr;
            if (data[i] == 'N') {
                i += 2;
                return nullptr;
            }
            bool neg = false;
            int val = 0;
            
            while (data[i] != ',') {
                if (data[i] == '-') {
                    neg = true;
                } else {
                    val = val * 10 + int(data[i] - '0');
                }
                i++;
            } i++;

            TreeNode* root = new TreeNode(neg? -val: val);
    
            root -> left = dfs(dfs);
            root -> right = dfs(dfs);
            return root;
        };

        return dfs(dfs);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode ans = deser.deserialize(ser.serialize(root));