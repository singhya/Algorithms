#include<iostream>
#include<unordered_map>
using namespace std;
struct Node{
    Node* prev;
    Node* next;
    int value;
    int key;
};
class LRUCache
{
private:
    Node* head;
    Node* tail;
    int capacity;
    unordered_map <int,Node*> mapping;
public:
    LRUCache(int cap){
        head = nullptr;
        tail = nullptr;
        capacity = cap;
    }
    void push_front(int key,int val){
        Node* new_node = new Node;
        mapping[key] = new_node;
        new_node->value = val;
        new_node->key = key;
        if(head)
        {
            new_node->next = head;
            new_node->prev = nullptr;
            head->prev = new_node;
            head = new_node;
        }
        else
        {
            new_node->next = nullptr;
            new_node->prev = nullptr;
            head = new_node;
            tail = new_node;
        }
    }
    void pop_back(){
        if(tail)
        {
            tail = tail->prev;
            if(tail)
            tail->next = nullptr;
        }
    }
    void display()
    {
        Node* traversor = new Node;
        traversor = head;
        while(traversor)
        {
            cout<<traversor->key<<endl;
            traversor = traversor->next;
        }
    }
    void escalate(Node* node)
    {
        if(!node->prev)
            return;
        else
        {
            node->prev->next = node->next;
            if(node->next)
                node->next->prev = node->prev;
            if(tail==node)
                tail = node->prev;
        }
        node->next = head;
        node->prev = nullptr;
        head->prev = node;
        head = node;
    }
    int get(int key)
    {
        if(mapping.count(key)==0)
        {
            return -1;
        }
        else
        {
            escalate(mapping[key]);
            return mapping[key]->value;
        }
    }
    int set(int key, int value)
    {
        if(mapping.count(key)>0)
        {
            escalate(mapping[key]);
            mapping[key]->value = value;
        }
        else
        {
            if(capacity==0)
            {
                mapping.erase(tail->key);
                pop_back();
			}
            else
            {
                capacity--;
            }
            push_front(key,value);
        }
    }

};
int main()
{
    LRUCache dl(2);
    dl.set(2,1);
    dl.set(1,1);
    cout<<dl.get(2)<<endl;
    dl.set(4,1);
    cout<<dl.get(1)<<endl;
    cout<<dl.get(2)<<endl;
    return 0;
}
