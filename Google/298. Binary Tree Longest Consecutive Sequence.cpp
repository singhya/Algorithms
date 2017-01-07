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
private:
    int longestSequence;
public:
    int DFS(TreeNode* root,int seq)
    {
        int max = seq;
        if(!root)
        {
            return seq;
        }
        if(root->left && root->left->val==root->val+1)
        {
            int new_seq = DFS(root->left,seq+1);
            if(new_seq>max)
                max = new_seq;
        }
        else
        {
            int new_seq = DFS(root->left,1);
            if(new_seq>max)
                max = new_seq;
        }
        if(root->right && root->right->val==root->val+1)
        {
            int new_seq = DFS(root->right,seq+1);
            if(new_seq>max)
                max = new_seq;
        }
        else
        {
            int new_seq = DFS(root->right,1);
            if(new_seq>max)
                max = new_seq;
        }
        return max;
    }
    int longestConsecutive(TreeNode* root) {
        if(!root)
            return 0;
        return DFS(root,1);
    }
};
