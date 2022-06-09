#include <bits/stdc++.h> 
Node *findMiddle(Node *head) {
    Node *slow = head, *fast = head;
    while(fast!=NULL and fast->next!=NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}