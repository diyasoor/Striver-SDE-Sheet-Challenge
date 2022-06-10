#include <bits/stdc++.h> 
LinkedListNode<int>* removeKthNode(LinkedListNode<int> *head, int K)
{
    LinkedListNode<int>* temp = new LinkedListNode<int>(1);
    LinkedListNode<int>* slow = temp;
    LinkedListNode<int>* fast = temp;
    temp->next = head;
    
    if(!head || K==0) return head;
    for(int i=0;i<K;i++) {
        fast = fast->next;
    }
    while(fast && fast->next) {
        fast = fast->next;
        slow = slow->next;
    }
    LinkedListNode<int> *d = slow->next;
    slow->next = slow->next->next;
    delete(d);
    return temp->next;
}