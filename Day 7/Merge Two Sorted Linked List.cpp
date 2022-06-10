#include <bits/stdc++.h> 
Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    Node<int>* third;
    if(!first) return second;
    if(!second) return first;
    
    if(first->data < second->data) {
        third = first;
        third->next = sortTwoLists(first->next,second);
    }
    else {
        third = second;
        third->next = sortTwoLists(first,second->next);
    }
    return third;
}
