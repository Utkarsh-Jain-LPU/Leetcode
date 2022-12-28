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
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* node = head;
        while (node->next != nullptr && node->next->next != nullptr) {
            head = head->next;
            node = node->next->next;
        }
        if (node->next == nullptr) {
            return head;
        }
        return head->next;
    }
};
