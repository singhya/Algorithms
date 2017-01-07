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
    int left_depth(TreeNode* root, int count){
        if(root==NULL) return count;
        return left_depth(root->left, count+1);
    }
    int right_depth(TreeNode* root, int count){
        if(root==NULL) return count;
        return right_depth(root->right, count+1);
    }
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        int left_ld = left_depth(root->left,0);
        int left_rd = right_depth(root->left,0);
        if(left_ld == left_rd)
            return countNodes(root->right) + (1<<left_ld);
        else
            return countNodes(root->left) + (1<<left_rd);
    }
};
