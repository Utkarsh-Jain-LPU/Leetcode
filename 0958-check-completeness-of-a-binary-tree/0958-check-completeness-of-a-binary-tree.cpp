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
    bool isNullFound = false;
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left == nullptr) isNullFound = true;
                else {
                    if (isNullFound) return false;
                    else q.push(node->left);
                }
                if (node->right == nullptr) isNullFound = true;
                else {
                    if (isNullFound) return false;
                    else q.push(node->right);
                }
            }
        }
        return true;
    }
};
