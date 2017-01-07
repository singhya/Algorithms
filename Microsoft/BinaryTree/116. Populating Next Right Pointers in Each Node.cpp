/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode* current = root;
        TreeLinkNode* prev = NULL;
        TreeLinkNode* head = NULL;
        while(current!=NULL) {
            while(current!=NULL){
                if(current->left!=NULL) {
                    if(prev==NULL) {
                        head = current->left;
                        prev = current->left;
                    }
                    else {
                        prev->next = current->left;
                        prev = prev->next;
                    }
                }
                if(current->right!=NULL) {
                    if(prev==NULL) {
                        head = current->right;
                        prev = current->right;
                    }
                    else {
                        prev->next = current->right;
                        prev = prev->next;
                    }
                }
                current = current->next;
            }
            current = head;
            prev = NULL;
            head = NULL;
        }
    }
};
