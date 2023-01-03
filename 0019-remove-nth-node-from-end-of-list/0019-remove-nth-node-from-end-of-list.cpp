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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode* var = head;
        while (var != nullptr) {
            count++;
            var = var->next;
        }
        if (count == n) {
            return head->next;
        }
        ListNode* prev = nullptr;
        ListNode* root = head;
        while (root != nullptr) {
            int i = n;
            ListNode* temp = root;
            while (i > 0) {
                temp = temp->next;
                i--;
            }
            if (temp == nullptr) {
                prev->next = root->next;
                break;
            }
            prev = root;
            root = root->next;
        }
        return head;
    }
};
