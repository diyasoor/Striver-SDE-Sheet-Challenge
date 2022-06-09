#include <bits/stdc++.h> 
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    LinkedListNode<int> *temp, *curr = head, *prev = NULL;
    while(curr!=NULL) {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    head = prev;
    return head;
}