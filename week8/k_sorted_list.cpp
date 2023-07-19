/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

 #include <queue>

class Solution {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode();

        ListNode* curr = dummy;

        std::priority_queue<std::pair<int, ListNode*>> pq;
        for (auto &l: lists) {
            if (l == nullptr) continue;
            pq.push({-(l -> val), l});
        }

        while (!pq.empty()) {
            auto [val, ptr] = pq.top(); pq.pop();
            curr -> next = ptr;
            curr = curr -> next;
            ptr = ptr -> next;
            if (ptr != nullptr) pq.push({-(ptr -> val), ptr});
        }

        return dummy -> next;

        
    }
};