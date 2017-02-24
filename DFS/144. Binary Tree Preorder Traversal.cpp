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
    void helper(TreeNode* root, vector<int>& result){
        if(root==NULL)
            return;
        result.push_back(root->val);
        helper(root->left, result);
        helper(root->right, result);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        helper(root, result);
        return result;
    }
};
