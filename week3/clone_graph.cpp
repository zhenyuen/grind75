#include <unordered_map>
#include <unordered_set>
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;

        std::unordered_map<Node*, Node*> map;
        std::unordered_set<Node*> visited;

        auto dfs = [&map, &visited] (Node* node, auto&& dfs) {
            if (visited.find(node) != visited.end()) return nullptr;

            if (map.find(node) == map.end()) {
                map[node] = new Node(node -> val);
            }


            for (auto a: node -> neighbors) {
                if (map.find(a) == map.end()) {
                    map[a] = new Node(a -> val);
                }
                map[node] -> neighbors.push_back(map[a]);
            }

            visited.insert(node);

            for (auto a: node -> neighbors) {
                dfs(a, dfs);
            }
            return nullptr;
        };

        dfs(node, dfs);
        return map[node];
    }
};