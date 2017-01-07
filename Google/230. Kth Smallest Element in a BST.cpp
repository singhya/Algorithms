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
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* ptr = root;
        stack<TreeNode*> st;
        while(ptr)
        {
            st.push(ptr);
            ptr = ptr->left;
        }
        while(!st.empty())
        {
            ptr = st.top();
            st.pop();
            if(k==1)
            {
                return ptr->val;
            }
            k--;
            if(ptr->right)
            {
                ptr=ptr->right;
                st.push(ptr);
                ptr = ptr->left;
                while(ptr)
                {
                    st.push(ptr);
                    ptr = ptr->left;
                }
            }
        }
        return -1;
    }
};
