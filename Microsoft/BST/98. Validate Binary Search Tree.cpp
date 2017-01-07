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
    bool helper(TreeNode* root, TreeNode* minNode, TreeNode* maxNode)
    {
        if(root==NULL)
            return true;
        if(maxNode!=NULL && root->val>=maxNode->val || minNode!=NULL && root->val<=minNode->val)
            return false;
        bool res = true;
        if(root->left!=NULL)
            res = res && helper(root->left, minNode, root);
        if(root->right!=NULL)
            res = res && helper(root->right, root, maxNode);
        return res;
    }
    bool isValidBST(TreeNode* root) {
        return helper(root,NULL,NULL);
    }
};
