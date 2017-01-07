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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    ListNode* top;
    Solution(ListNode* head) {
        top = head;
    }

    /** Returns a random node's value. */
    int getRandom() {
        ListNode* current=top;
        ListNode* result;
        for(int i=1;current!=NULL;i++)
        {
            if((rand()%i)==0)
                result = current;
            current = current->next;
        }
        return result->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
