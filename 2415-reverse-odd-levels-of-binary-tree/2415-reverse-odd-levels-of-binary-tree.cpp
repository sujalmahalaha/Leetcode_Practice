/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* rootLeft, TreeNode* rootRight, int level) {
        if (rootLeft == NULL || rootRight == NULL)
            return;
        if (level % 2 == 1) {
            int temp = rootLeft->val;
            rootLeft->val = rootRight->val;
            rootRight->val = temp;
        }
        solve(rootLeft->left, rootRight->right, level + 1);
        solve(rootLeft->right, rootRight->left, level + 1);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        solve(root->right, root->left, 1);
        return root;
    }
};