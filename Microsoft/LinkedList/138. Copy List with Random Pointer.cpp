/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == NULL)
            return NULL;
        RandomListNode* temp = head;
        while(temp!=NULL)
        {
            RandomListNode* newNode = new RandomListNode(temp->label);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = temp->next->next;
        }
        temp = head;
        while(temp!=NULL)
        {
            if(temp->random!=NULL)
                temp->next->random = temp->random->next;
            temp = temp->next->next;
        }

        RandomListNode* copiedHead = head->next;
        temp = head;
        RandomListNode* copied;
        while(temp->next->next!=NULL)
        {
            copied = temp->next;
            temp->next = temp->next->next;
            copied->next = temp->next->next;
            temp = temp->next;
        }
        temp->next = NULL;
        return copiedHead;
    }
};
