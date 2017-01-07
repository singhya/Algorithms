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
    int max = INT_MIN;
    int helper(TreeNode* root){
        if(root==NULL)
            return 0;
        int left_path = std::max(helper(root->left),0);
        int right_path = std::max(helper(root->right),0);
        max = std::max(max,left_path+right_path+root->val);
        return std::max(left_path+root->val,right_path+root->val);
    }
    int maxPathSum(TreeNode* root) {
        helper(root);
        return max;
    }
};
