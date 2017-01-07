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
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, unordered_map<int, int> &m, int in_start, int in_end, int post_start, int post_end){
        if(in_start>in_end){
            return NULL;
        }
        if(in_start==in_end){
            TreeNode* node = new TreeNode(postorder[post_end]);
            return node;
        }
        int inorder_index = m[postorder[post_end]];
        TreeNode* left_tree = helper(inorder, postorder, m, in_start, inorder_index - 1, post_start, post_start + inorder_index - in_start -1);
        TreeNode* right_tree = helper(inorder, postorder, m, inorder_index+1, in_end, post_start + inorder_index - in_start, post_end-1);
        TreeNode* node = new TreeNode(postorder[post_end]);
        node->left = left_tree;
        node->right = right_tree;
        return node;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> m;
        int n = postorder.size();
        for(int i=0;i<n;i++){
            m[inorder[i]] = i;
        }
        return helper(inorder,postorder,m,0,n-1,0,n-1);
    }
};
