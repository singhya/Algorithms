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
    class SubTree{
        public:
        int elements;
        TreeNode* max;
        TreeNode* min;
        SubTree(int e, TreeNode* minimum, TreeNode* maximum){
            elements = e;
            max = maximum;
            min = minimum;
        }
    };
    int max = 1;
    SubTree* helper(TreeNode* root){
        if(root==NULL)
            return new SubTree(0,NULL,NULL);
        if(root->left==NULL && root->right==NULL)
            return new SubTree(1,root,root);
        SubTree* left_tree = helper(root->left);
        SubTree* right_tree = helper(root->right);
        if(left_tree->elements==-1 || right_tree->elements==-1 || (left_tree->elements!=0 && left_tree->max->val>=root->val) || (right_tree->elements!=0 && root->val>=right_tree->min->val))
            return new SubTree(-1,NULL,NULL);
        int size = left_tree->elements + right_tree->elements + 1;
        max = std::max(size,max);
        TreeNode* maximum  = (root->right!=NULL)? right_tree->max : root;
        TreeNode* minimum = (root->left!=NULL)? left_tree->min : root;
        SubTree* to_return = new SubTree(size,minimum,maximum);
        return to_return;
    }
    int largestBSTSubtree(TreeNode* root) {
        if(root==NULL)
            return 0;
        helper(root);
        return max;
    }
};
