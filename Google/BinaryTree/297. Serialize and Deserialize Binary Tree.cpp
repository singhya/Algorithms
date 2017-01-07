/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
            return "null";
        string left = serialize(root->left);
        string right = serialize(root->right);
        return to_string(root->val) + "," + left + "," + right;

    }
    void split(const string &s, char delim, vector<string> &elems) {
        stringstream ss(s);
        string item;
        while (getline(ss, item, delim))
        {
            elems.push_back(item);
        }
    }


    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector <string> fields;
        split(data, ',', fields );
        stack<TreeNode*> st;
        TreeNode* root;
        if(fields[0]=="null")
        {
            return NULL;
        }
        int n = fields.size();
        int i=0;
        while(i<n)
        {
            while(i<n && fields[i]!="null")
            {
                TreeNode *ptr = new TreeNode(stoi(fields[i]));
                if(i==0)
                {
                    root = ptr;
                }
                else
                {
                    st.top()->left = ptr;
                }
                st.push(ptr);
                i++;
            }
            i++;
            while(i<n && fields[i]=="null")
            {
                st.pop();
                i++;
            }
            if(i<n)
            {
                TreeNode *ptr = new TreeNode(stoi(fields[i]));
                st.top()->right = ptr;
                st.pop();
                st.push(ptr);
                i++;
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
