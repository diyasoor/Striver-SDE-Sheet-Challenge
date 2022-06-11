#include <bits/stdc++.h> 
Node* merge(Node* l1, Node *l2) {    
    if(!l1) return l2;
    if(!l2) return l1;
    Node *l3;
    
    if(l1->data < l2->data) {
        l3 = l1;
        l3->child = merge(l1->child,l2);
    }
    else {
        l3 = l2;
        l3->child = merge(l1,l2->child);
    }
    l3->next = NULL;
    return l3;
}
Node* flattenLinkedList(Node* head) 
{
	if(!head || !head->next) return head;
    return merge(head,flattenLinkedList(head->next));
}
