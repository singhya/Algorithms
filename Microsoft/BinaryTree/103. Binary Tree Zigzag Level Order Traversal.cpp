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
    vector<vector<int>>result;
    void helper(TreeNode* root, int level){
        if(root == NULL){
            return;
        }
        if(level%2==0){
            if(result.size()<=level){
                vector<int> v;
                v.push_back(root->val);
                result.push_back(v);
            }
            else
                result[level].push_back(root->val);
        }
        else{
            if(result.size()<=level){
                vector<int> v;
                v.push_back(root->val);
                result.push_back(v);
            }
            else
                result[level].insert(result[level].begin(), root->val);
        }
        helper(root->left,level+1);
        helper(root->right,level+1);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        helper(root,0);
        return result;
    }
};
