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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        int carry = 0;
        ListNode* result;
        if(l1==NULL)
            return l2;
        else if(l2==NULL)
            return l1;
        else {
            result = new ListNode((l1->val+l2->val)%10);
            carry = (l1->val+l2->val)/10;
            t1=l1->next;
            t2=l2->next;
        }
        ListNode* res = result;
        while(t1!=NULL && t2!=NULL)
        {
            ListNode* new_node = new ListNode((t1->val+t2->val+carry)%10);
            carry = (t1->val+t2->val+carry)/10;
            res->next = new_node;
            res = res->next;
            t1 = t1->next;
            t2 = t2->next;
        }
        while(t1!=NULL) {
            ListNode* new_node = new ListNode((t1->val+carry)%10);
            carry = (t1->val+carry)/10;
            res->next = new_node;
            res = res->next;
            t1 = t1->next;
        }
        while(t2!=NULL) {
            ListNode* new_node = new ListNode((t2->val+carry)%10);
            carry = (t2->val+carry)/10;
            res->next = new_node;
            res = res->next;
            t2 = t2->next;
        }
        if(carry==1) {
            ListNode* new_node = new ListNode(carry);
            res->next = new_node;
        }
        return result;
    }
};
