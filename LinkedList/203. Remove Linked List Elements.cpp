/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL)
            return head;
        if(head->val==val){
            ListNode* next = removeElements(head->next, val);
            if(next == NULL)
                return NULL;
            else{
                head->val = next->val;
                head->next = next->next;
            }
        }
        else
            head->next = removeElements(head->next, val);
        return head;
    }
};
