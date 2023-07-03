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
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr and list2 == nullptr) return nullptr;

        ListNode* dummy = new ListNode;
        ListNode* curr = dummy;
        
        while (list1 != nullptr && list2 != nullptr) {
            auto l1_val = list1 -> val;
            auto l2_val = list2 -> val;

            if (l1_val > l2_val) {
                curr -> next = list2;
                list2 = list2 -> next;
            } else {
                curr -> next = list1;
                list1 = list1 -> next;
            }
            curr = curr -> next;
        }

        if (list1 == nullptr) {
            curr -> next = list2;
        } else {
            curr -> next = list1;
        }
        curr = dummy -> next;
        delete dummy;
        return curr;
    }
};