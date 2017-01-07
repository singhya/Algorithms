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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result(0);
        if(root==NULL)
            return result;
        if(root->left)
            result = binaryTreePaths(root->left);
        if(root->right)
        {
            vector<string> right_result = binaryTreePaths(root->right);
            result.insert(result.end(),right_result.begin(),right_result.end());
        }
        for(int i=0;i<result.size();i++)
        {
            result[i]=to_string(root->val)+"->"+result[i];
        }
        if(result.size()==0)
        {
            result.push_back(to_string(root->val));
        }
        return result;
    }
};
