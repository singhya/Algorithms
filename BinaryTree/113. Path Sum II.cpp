/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> result;
    void helper(TreeNode* root, int sum, vector<int> path){
        if(root==NULL)
            return;
        path.push_back(root->val);
        if(root->left==NULL && root->right==NULL && root->val == sum) {
            result.push_back(path);
            return;
        }
        helper(root->left, sum-root->val, path);
        helper(root->right, sum-root->val, path);
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int>v;
        helper(root, sum, v);
        return result;
    }
};
