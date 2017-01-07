/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Element{
    public:
    TreeNode* node;
    int level;
    Element(TreeNode* n, int l){
        node = n;
        level = l;
    }
};
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root==NULL)
            return result;
        Element *e = new Element(root, 0);
        queue<Element*> q;
        q.push(e);
        int level = -1;
        while(!q.empty())
        {
            Element* parent = q.front();
            q.pop();
            if(parent->level!=level) {
                vector<int>v;
                v.push_back(parent->node->val);
                result.push_back(v);
                level++;
            }
            else {
                result[level].push_back(parent->node->val);
            }
            if(parent->node->left!=NULL) {
                q.push(new Element(parent->node->left,parent->level+1));
            }
            if(parent->node->right!=NULL) {
                q.push(new Element(parent->node->right,parent->level+1));
            }
        }
        return result;

    }
};
