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
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        stack<TreeNode*>Preds;
        stack<TreeNode*>Succs;
        Preds = InitializePreds(root,target);
        Succs = InitializeSuccs(root,target);
        vector<int> result;
        while(k--)
        {
            if(Preds.empty())
            {
                TreeNode* node = Succs.top();
                Succs.pop();
                getNextSuccs(node,Succs);
                result.push_back(node->val);
            }
            else if(Succs.empty())
            {
                TreeNode* node = Preds.top();
                Preds.pop();
                getNextPreds(node,Preds);
                result.push_back(node->val);
            }
            else
            {
                TreeNode* succNode = Succs.top();
                TreeNode* predNode = Preds.top();
                if(abs(succNode->val-target)==abs(predNode->val-target) && abs(((double)predNode->val)-target)==0)
                {
                    Preds.pop();
                    getNextPreds(predNode,Preds);
                    result.push_back(predNode->val);
                    Succs.pop();
                    getNextSuccs(succNode,Succs);
                }
                else if(abs(succNode->val-target)<abs(predNode->val-target))
                {
                    Succs.pop();
                    getNextSuccs(succNode,Succs);
                    result.push_back(succNode->val);
                }
                else
                {
                    Preds.pop();
                    getNextPreds(predNode,Preds);
                    result.push_back(predNode->val);
                }
            }
        }
        return result;
    }
    stack<TreeNode*> InitializePreds(TreeNode* root,double target)
    {
        stack<TreeNode*>Preds;
        while(root)
        {
            if(root->val<target)
            {
                Preds.push(root);
                root=root->right;
            }
            else if(root->val>target)
                root = root->left;
            else
            {
                Preds.push(root);
                break;
            }
        }
        return Preds;
    }
    stack<TreeNode*> InitializeSuccs(TreeNode* root,double target)
    {
        stack<TreeNode*>Succs;
        while(root)
        {
            if(root->val>target)
            {
                Succs.push(root);
                root = root->left;
            }
            else if(root->val<target)
                root = root->right;
            else
            {
                Succs.push(root);
                break;
            }
        }
        return Succs;
    }
    void getNextSuccs(TreeNode* root,stack<TreeNode*>& Succs)
    {
        root = root->right;
        while(root)
        {
            Succs.push(root);
            root = root->left;
        }
    }
    void getNextPreds(TreeNode* root,stack<TreeNode*>& Preds)
    {
        root = root->left;
        while(root)
        {
            Preds.push(root);
            root = root->right;
        }
    }

};
