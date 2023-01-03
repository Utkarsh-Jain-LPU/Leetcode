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
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr) return head;
        ListNode *first = nullptr;
        ListNode *temp1 = nullptr;
        ListNode *second = nullptr;
        ListNode *temp2 = nullptr;
        while (head != nullptr) {
            ListNode* node = new ListNode(head->val);
            if (head->val < x) {
                if (first == nullptr) {
                    first = temp1 = node;
                } else {
                    temp1->next = node;
                    temp1 = temp1->next;
                }
            } else {
                if (second == nullptr) {
                    second = temp2 = node;
                } else {
                    temp2->next = node;
                    temp2 = temp2->next;
                }
            }
            head = head->next;
        }
        if (first == nullptr) return second;
        if (second == nullptr) return first;
        temp1->next = second;
        return first;
    }
};