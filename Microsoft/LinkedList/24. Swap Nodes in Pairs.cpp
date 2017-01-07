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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* first = head;
        ListNode* second = head->next;
        ListNode* newHead = second;
        ListNode* prev=NULL;
        do
        {
            first->next = second->next;
            second->next = first;
            if(prev!=NULL)
                prev->next = second;
            prev = first;
            first = first->next;
            if(first==NULL)
                break;
            second = first->next;
        }while(second!=NULL);
        return newHead;
    }
};
