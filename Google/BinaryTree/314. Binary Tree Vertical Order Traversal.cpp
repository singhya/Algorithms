/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class node{
    public:
        int column;
        TreeNode* n;
        node(TreeNode *node,int col)
        {
            n = node;
            column = col;
        }
};
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        queue<node>q;
        vector<vector<int>>result;
        if(root==NULL)
            return result;
        node n(root,0);
        map<int,vector<int>>res;
        q.push(n);
        int min = 0;
        int max = 0;
        while(!q.empty())
        {
            node parent = q.front();
            q.pop();
            if(res.find(parent.column)==res.end())
            {
                vector<int> v;
                v.push_back(parent.n->val);
                res[parent.column] = v;
            }
            else
                res[parent.column].push_back(parent.n->val);
            if(parent.n->left)
            {
                node new_node(parent.n->left,parent.column-1);
                min = std::min(min,parent.column-1);
                q.push(new_node);
            }
            if(parent.n->right)
            {
                node new_node(parent.n->right,parent.column+1);
                max = std::max(max,parent.column+1);
                q.push(new_node);
            }
        }
        while(min<=max)
        {
            result.push_back(res[min++]);
        }
        return result;
    }
};
