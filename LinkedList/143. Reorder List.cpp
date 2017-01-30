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
    ListNode* reverse(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* first = head;
        ListNode* second = head->next;
        ListNode* third = head->next->next;
        while(second!=NULL){
            second->next = first;
            first = second;
            second = third;
            if(third!=NULL)
                third = third->next;
        }
        head->next = NULL;
        return first;

    }
    ListNode* reorderList(ListNode* head){
         if(head==NULL) return head;
         ListNode* slow = head;
         ListNode* fast = head;
         while(fast!=NULL && fast->next!=NULL){
             slow = slow->next;
             fast = fast->next->next;
         }
         ListNode* mid = slow;
         mid->next = reverse(mid->next);
         ListNode* temp = mid->next;
         while(temp !=NULL)
             temp = temp->next;
         ListNode* firstHalf = head;
         ListNode* secondHalf = mid->next;
         while(secondHalf!=NULL){
             ListNode* next = firstHalf->next;
             firstHalf->next = secondHalf;
             secondHalf = secondHalf->next;
             firstHalf->next->next = next;
             firstHalf = next;
             mid->next = secondHalf;
         }
         return head;
    }
};
