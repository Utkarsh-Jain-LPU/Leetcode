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
    int calculate(TreeNode* root) {
        if (root == nullptr) return 0;
        if (root->left == nullptr && root->right == nullptr) {
            res = max(res, root->val);
            return root->val;
        }
        int left = calculate(root->left);
        int right = calculate(root->right);
        int temp = max(root->val, max(left, right) + root->val);
        temp = max(temp, left + right + root->val);
        res = max(res, temp);
        return max(root->val, max(left, right) + root->val);
    }
    int maxPathSum(TreeNode* root) {
        calculate(root);
        return res;
    }
};
