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
    ListNode* reverse(ListNode* head){
        ListNode* first = head;
        if(first->next==NULL)
            return first;
        ListNode* second = first->next;
        ListNode* third = second->next;
        first->next = NULL;
        while(third!=NULL){
            second->next = first;
            first = second;
            second = third;
            third = third->next;
        }
        second->next = first;
        return second;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* next = head;
        ListNode* prev = NULL;
        ListNode* to_return = head;
        while(next!=NULL){
            int i=0;
            ListNode* iterator = next;
            while(i++<k-1 && iterator!=NULL)
                iterator = iterator->next;
            if(iterator==NULL)
                break;
            ListNode* temp = iterator->next;
            iterator->next = NULL;
            ListNode* reversed = reverse(next);
            if(prev==NULL)
                to_return = reversed;
            else
                prev->next = reversed;
            prev = next;
            next->next = temp;
            next = temp;
        }
        return to_return;
    }
};
