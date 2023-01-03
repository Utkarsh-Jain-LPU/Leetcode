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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        bool isDeleteCurr = false;
        ListNode *prev, *curr, *next;
        prev = nullptr, curr = head, next = head->next;
        while (next != nullptr) {
            if (curr->val == next->val) {
                isDeleteCurr = true;
                curr->next = next->next;
                next = next->next;
            } else {
                if (isDeleteCurr) {
                    if (prev == nullptr) {
                        head = next;
                        curr = next;
                        next = next->next;
                    } else {
                        prev->next = next;
                        curr = next;
                        next = next->next;
                    }
                    isDeleteCurr = false;
                } else {
                    prev = curr;
                    curr = next;
                    next = next->next;
                }
            }
        }
        if (isDeleteCurr) {
            if (prev == nullptr) {
                head = next;
            } else {
                prev->next = next;
            }
        }
        return head;
    }
};
