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
    vector<int> largestValues(TreeNode* root) {
        if(root == NULL)return {};
        vector<int>ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            int maxi = INT_MIN;
            while(n--){
                TreeNode* Node = q.front();
                q.pop();
                int val = Node->val;
                maxi = max(maxi , val);
                if(Node->left){
                    q.push(Node->left);
                }
                if(Node->right){
                    q.push(Node->right);
                }
            }
            ans.push_back(maxi);
        }
        return ans;
        
    }
};