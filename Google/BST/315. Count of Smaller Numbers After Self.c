class Node
{
    public:
    Node* left;
    Node* right;
    int total;
    int value;
    Node(int val)
    {
        value = val;
        total = 0;
        left = NULL;
        right = NULL;
    }
};
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(n);
        Node* root=NULL;
        for(int i=n-1;i>=0;i--)
            root = insert(nums[i],count,root,0,i);
        return count;
    }
    Node* insert(int num, vector<int> &count,Node* root,int sum,int index)
    {
        if(root==NULL)
        {
            Node* new_node = new Node(num);
            count[index] = sum;
            return new_node;
        }
        else if(num>root->value)
        {
            root->right = insert(num,count,root->right,sum+1+root->total,index);
            return root;
        }
        else
        {
            root->total++;
            root->left = insert(num,count,root->left,sum,index);
            return root;
        }
    }
};
