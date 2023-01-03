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
    int findMin(vector<ListNode*>& lists) {
        int i = 0;
        int min = INT_MAX;
        int index = 0;
        for (auto k=lists.begin(); k!=lists.end(); k++, i++) {
            if ((*k)->val < min) {
                min = (*k)->val;
                index = i;
            }
        }
        lists[index] = lists[index]->next;
        if (lists[index] == nullptr) {
            lists.erase(lists.begin()+index);
        }
        return min;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for (auto it=lists.begin(); it!=lists.end(); it++) {
            if ((*it) == nullptr) {
                lists.erase(it);
                it--;
            }
        }
        if (lists.size() == 0) {
            return nullptr;
        }
        ListNode* head = nullptr;
        ListNode* root = head;
        while (lists.size() != 0) {
            int val = findMin(lists);
            ListNode* node = new ListNode(val);
            if (root == nullptr) {
                root = head = node;
            } else {
                root->next = node;
                root = root->next;
            }
        }
        return head;
    }
};
