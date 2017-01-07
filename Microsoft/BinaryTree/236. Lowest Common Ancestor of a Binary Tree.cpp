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
    bool isPresent(TreeNode* root, TreeNode* node)
    {
        if(root==NULL)
            return false;
        if(root==node)
            return true;
        if(isPresent(root->left,node) || isPresent(root->right,node))
            return true;
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==p || root==q)
            return root;
        bool isPLeft = isPresent(root->left,p);
        bool isQLeft = isPresent(root->left,q);
        if(root!=NULL && isPLeft && isQLeft)
            return lowestCommonAncestor(root->left,p,q);
        else if(root!=NULL && !isPLeft && !isQLeft)
            return lowestCommonAncestor(root->right,p,q);
        else
            return root;
    }
};
