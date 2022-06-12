#include <bits/stdc++.h> 
LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    LinkedListNode<int> *iter = head, *front = head;

    // First Step: make a copy of each node,
    // and link them together side-by-side in a single list
    while(iter != NULL) {
        front = iter->next;
        LinkedListNode<int> *copy = new LinkedListNode<int>(iter->data);
        iter->next = copy;
        copy->next = front;
        iter = front;
    }

    // Second Step: assign random pointers for the copy nodes.
    iter = head;
    while(iter!=NULL) {
        iter->next->random = iter->random;     
        iter = iter->next->next;
    }

    // Third Step: Restore the original list, and extract the copy list.
    iter = head;
    LinkedListNode<int> *dummy = new LinkedListNode<int>(0);
    LinkedListNode<int> *copy = dummy;

    while(iter!=NULL) {
        front = iter->next->next;
        // extract the copy 
        copy->next = iter->next;
        // restore the original list 
        iter->next = front;
        copy = copy->next;
        iter = front;
    }
    return dummy->next;
}
