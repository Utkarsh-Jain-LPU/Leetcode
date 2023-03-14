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
    vector<string> find(TreeNode* root) {
        if (root == nullptr) return {};
        if (root->left == nullptr && root->right == nullptr) return { to_string(root->val) };
        vector<string> left = find(root->left);
        vector<string> right = find(root->right);
        vector<string> vec;
        for (string val : left) vec.push_back(to_string(root->val)+val);
        for (string val : right) vec.push_back(to_string(root->val)+val);
        return vec;
    }
    int sumNumbers(TreeNode* root) {
        vector<string> v = find(root);
        int res = 0;
        for (string val : v) res += stoi(val);
        return res;
    }
};
