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
    int closestValue(TreeNode* root, double target) {
        if(root->val==target)
            return root->val;
        if(target<root->val)
        {
            if(root->left)
            {
                int val = closestValue(root->left,target);
                if(abs(val-target)<abs(root->val-target))
                    return val;
                else
                    return root->val;
            }
            else
                return root->val;
        }
        else
        {
            if(root->right)
            {
                int val = closestValue(root->right,target);
                if(abs(val-target)<abs(root->val-target))
                    return val;
                else
                    return root->val;
            }
            else
                return root->val;
        }
    }
};
