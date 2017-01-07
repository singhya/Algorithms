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
    int helper(ListNode* node)
    {
        if(node->next==NULL)
        {
            if(node->val+1==10)
            {
                node->val = 0;
                return 1;
            }
            else
                node->val = node->val+1;
            return 0;
        }
        else
        {
            int res = helper(node->next);
            if(res+node->val==10)
            {
                node->val = 0;
                return 1;
            }
            else node->val = node->val+res;
        }
        return 0;

    }
    ListNode* plusOne(ListNode* head) {
        int res = helper(head);
        if(res == 1)
        {
            ListNode *h = new ListNode(1);
            h->next = head;
            return h;
        }
        return head;
    }
};
