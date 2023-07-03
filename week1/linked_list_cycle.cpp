/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr) return false;

        auto first = succ(head);
        auto second = succ(succ(head));

        while (first != second) {
            first = succ(first);
            second = succ(succ(second));
        }

        return first != nullptr and second != nullptr and first == second;
    }

    ListNode* succ(ListNode *node) {
        if (node == nullptr) return nullptr;
        return node -> next;
    }
};