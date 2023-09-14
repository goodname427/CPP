#include <bits/stdc++.h>
#include "../util/crand"
using namespace std;

class linked_node
{
public:
    int val;
    linked_node *next;

    linked_node() : linked_node(0, NULL) {}
    linked_node(int val) : linked_node(val, NULL) {}
    linked_node(int val, linked_node *next) : val(val), next(next) {}

    ~linked_node()
    {
        if(next)
            delete next;
    }
};

linked_node* randomly_linked_list(int max_size, int max_value)
{
    int size = random(max_size);
    linked_node* head = new linked_node(random(max_value));
    linked_node* cur = head;
    while(size--) 
    {
        cur->next = new linked_node(random(max_value));
        cur = cur->next;
    }
    return head;
}
