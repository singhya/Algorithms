/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct less_than_key
{
    bool operator() (const ListNode* lhs, const ListNode* rhs)
    {
        return lhs->val < rhs->val;
    }
};

class Solution {
public:

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        multiset<ListNode*,less_than_key> min_heap;
        for(int i=0;i<lists.size();i++)
        {
            if(lists[i])
            {
                min_heap.insert(lists[i]);
                lists[i]=lists[i]->next;
            }
        }

        ListNode* result = nullptr;
        ListNode* temp;
        while(min_heap.size()>0)
        {
            auto it = min_heap.begin();
            int minimum = (*(it))->val;
            ListNode* new_node = new ListNode(minimum);
            if(result)
            {
                temp->next = new_node;
                temp = temp->next;
            }
            else
            {
                result = new_node;
                temp = result;
            }
            if((*(it))->next)
                min_heap.insert((*(it))->next);
            min_heap.erase(it);
        }
        return result;
    }
};
