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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* root;
    void formTree(vector<int>& vec, int i, int j, TreeNode* node, int pos) {
        if (i > j) return;
        int mid = ceil((i+j)/2.0);
        if (pos == 0) {
            root = node = new TreeNode(vec[mid]);
            formTree(vec, i, mid-1, node, -1);
            formTree(vec, mid+1, j, node, 1);
        } else if (pos == -1) {
            node->left = new TreeNode(vec[mid]);
            formTree(vec, i, mid-1, node->left, -1);
            formTree(vec, mid+1, j, node->left, 1);
        } else {
            node->right = new TreeNode(vec[mid]);
            formTree(vec, i, mid-1, node->right, -1);
            formTree(vec, mid+1, j, node->right, 1);
        }
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> v;
        while (head != nullptr) {
            v.push_back(head->val);
            head = head->next;
        }
        formTree(v, 0, v.size()-1, root, 0);
        return root;
    }
};
