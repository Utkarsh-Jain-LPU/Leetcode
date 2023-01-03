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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* root = head;
        int size = 1;
        while (root->next != nullptr) {
            size++;
            root = root->next;
        }
        k = k%size;
        if (k == 0) return head;
        int n = size-k-1;
        ListNode* curr = head;
        while (n > 0) {
            curr = curr->next;
            n--;
        }
        root->next = head;
        head = curr->next;
        curr->next = nullptr;
        return head;
    }
};
