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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a = headA;
        ListNode* b = headB;
        while(a!=NULL && b!=NULL)
        {
            if(a==b)
                return a;
            a = a->next;
            b = b->next;
            if(a==NULL && b==NULL)
                return NULL;
            else if(a==NULL)
                a = headB;
            else if(b==NULL)
                b = headA;
        }
        return NULL;
    }
};
