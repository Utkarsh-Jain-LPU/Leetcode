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
    long long sum = 0;
    long long maxVal = 0;
    int MAX = 1000000007;
    void totalSum(TreeNode* root) {
        if (root == nullptr) return;
        sum += root->val;
        totalSum(root->left);
        totalSum(root->right);
    }
    void calculate(TreeNode* root, int& total) {
        if (root == nullptr) return;
        if (root->left == nullptr && root->right == nullptr) {
            total += root->val;
            maxVal = max(maxVal, total*(sum-total));
            return;
        }
        int left = 0;
        calculate(root->left, left);
        int right = 0;
        calculate(root->right, right);
        total += left + right + root->val;
        maxVal = max(maxVal, total*(sum-total));
    }
    int maxProduct(TreeNode* root) {
        totalSum(root);
        int total = 0;
        calculate(root, total);
        return maxVal % MAX;
    }
};
