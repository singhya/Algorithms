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
    int helper(TreeNode* root, int level){
        if(root==NULL)
            return level;
        return max(helper(root->left,level+1),helper(root->right,level+1));
    }
    int maxDepth(TreeNode* root) {
        return helper(root,0);
    }
};
