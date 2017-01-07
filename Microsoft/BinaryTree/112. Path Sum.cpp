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
    bool helper(TreeNode* root, int sum, int currentSum){
        if(root==NULL)
            return false;
        if(root->left==NULL && root->right==NULL)
            if(sum==currentSum+root->val)
                return true;
            else
                return false;
        if(helper(root->left,sum,currentSum+root->val))
            return true;
        if(helper(root->right,sum,currentSum+root->val))
            return true;
        return false;
    }
    bool hasPathSum(TreeNode* root, int sum) {
        return helper(root,sum,0);
    }
};
