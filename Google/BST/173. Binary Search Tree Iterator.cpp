/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
    stack<TreeNode*>s;
public:
    BSTIterator(TreeNode *root) {
        TreeNode* temp;
        temp = root;
        while(temp)
        {
            s.push(temp);
            temp=temp->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* result = s.top();
        s.pop();
        TreeNode* temp = result->right;
        if(temp)
        {
            s.push(temp);
            temp = temp->left;
        }
        return result->val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
