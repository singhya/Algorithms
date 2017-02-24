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
    int helper(TreeNode* root, bool isLeft){
        if(root==NULL) return 0;
        if(isLeft && root->left==NULL && root->right==NULL) return root->val;
        return helper(root->left, true) + helper(root->right, false);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return helper(root, false);
    }
};
