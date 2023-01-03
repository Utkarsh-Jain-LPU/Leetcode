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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = l1->val + l2->val;
        int num = sum%10;
        int carry = sum/10;
        l1 = l1->next;
        l2 = l2->next;
        ListNode* head = new ListNode(num);
        ListNode* root = head;
        while (l1 != nullptr && l2 != nullptr) {
            sum = l1->val + l2->val + carry;
            num = sum%10;
            carry = sum/10;
            ListNode* node =  new ListNode(num);
            root->next = node;
            root = root->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        ListNode* temp = (l1 != nullptr) ? l1 : l2;
        while (temp != nullptr) {
            sum = temp->val + carry;
            num = sum%10;
            carry = sum/10;
            ListNode* node =  new ListNode(num);
            root->next = node;
            root = root->next;
            temp = temp->next;
        }
        if (carry > 0) {
            ListNode* node =  new ListNode(carry);
            root->next = node;
        }
        return head;
    }
};
