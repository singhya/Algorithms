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
    bool hasCycle(ListNode *head) {
            if(head == NULL || head-> next == NULL)
                return false;
            ListNode* back = head;
            ListNode* front = head-> next;
            while(front-> next != NULL && front->next->next!=NULL && back!=front){
                front = front->next->next;
                back = back->next;}
            if(back==front)
                return true;
            return false;

    }
};
