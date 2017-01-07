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
    bool helper(TreeNode* first, TreeNode* second)
    {
        if(first==NULL && second==NULL)
            return true;
        else if((first==NULL && second!=NULL) || (first!=NULL && second==NULL) || first->val != second->val)
            return false;
        return helper(first->left,second->right) && helper(first->right,second->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
            return true;
        return helper(root->left,root->right);
    }
};
