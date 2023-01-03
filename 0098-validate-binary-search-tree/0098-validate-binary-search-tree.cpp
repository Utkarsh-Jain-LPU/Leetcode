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
    bool isValid = true;
    vector<int> calculate(TreeNode* root) {
        vector<int> vec;
        if (root == nullptr) return vec;
        if (root->left == nullptr && root->right == nullptr) {
            vec.push_back(root->val);
            return vec;
        }
        vector<int> leftVec = calculate(root->left);
        for (int val : leftVec) {
            vec.push_back(val);
            if (val >= root->val) isValid = false;
        }
        if (!isValid) return vec;
        vector<int> rightVec = calculate(root->right);
        for (int val : rightVec) {
            vec.push_back(val);
            if (val <= root->val) isValid = false;
        }
        if (!isValid) return vec;
        vec.push_back(root->val);
        return vec;
    }
    bool isValidBST(TreeNode* root) {
        calculate(root);
        return isValid;
    }
};
