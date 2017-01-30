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
    ListNode* reverse(ListNode* head, int n){
        if(n==1) return head;
        ListNode* first = head;
        ListNode* second = head->next;
        ListNode* third = head->next->next;
        while(n>1 && second!=NULL){
            second->next = first;
            first = second;
            second = third;
            if(third!=NULL)
                third = third->next;
            n--;
        }
        head->next = second;
        return first;
    }
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m==1)
            return reverse(head, n);
        else{
            head->next = reverseBetween(head->next, m-1, n-1);
            return head;
        }
    }
};
