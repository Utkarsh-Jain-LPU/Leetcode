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
    int res = INT_MIN;
    void calculate(TreeNode* root, vector<int>& vec) {
        if (root == nullptr) return;
        if (root->left == nullptr && root->right == nullptr) {
            vec.push_back(root->val);
            return;
        }
        vector<int> left;
        calculate(root->left, left);
        vector<int> right;
        calculate(root->right, right);
        for (int val : left) {
            vec.push_back(val);
            res = max(res, abs(val-(root->val)));
        }
        for (int val : right) {
            vec.push_back(val);
            res = max(res, abs(val-(root->val)));
        }
        vec.push_back(root->val);
    }
    int maxAncestorDiff(TreeNode* root) {
        vector<int> vec;
        calculate(root, vec);
        return res;
    }
};
