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
    void find(TreeNode* root, set<int>& v) {
        if (root == nullptr) return;
        v.insert(root->val);
        find(root->left, v);
        find(root->right, v);
    }
    int minDiffInBST(TreeNode* root) {
        set<int> v;
        find(root, v);
        int res = INT_MAX, temp = INT_MAX;
        for (auto it=v.begin(); it!=v.end(); it++) {
            res = min(res, abs(temp-*it));
            temp = *it;
        }
        return res;
    }
};
