#include <bits/stdc++.h> 
Node *rotate(Node *head, int k) {
    if(!head || !head->next || k==0) return head; 
    int cnt = 0;
    Node *temp = head, *prev;
    while(temp) {
        cnt++;
        prev = temp;
        temp = temp->next;
    }
    prev->next = head;
    k = k % cnt;
    k = cnt - k;
    temp = head;
    while(k > 0) {
        prev = temp;
        temp = temp->next;
        k--;
    }
    prev->next = NULL;
    return temp;
}