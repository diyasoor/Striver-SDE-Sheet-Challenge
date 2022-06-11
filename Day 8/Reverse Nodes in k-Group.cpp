#include <bits/stdc++.h> 
Node *getListAfterReverseOperation(Node *head, int n, int b[]){
    if(head==NULL || head->next==NULL) return head;
    Node *temp = new Node(0);
    temp->next = head;
    Node *curr=temp, *prev=temp, *next=temp;
    int cnt=0;
    while(curr->next) {
        curr = curr->next;
        cnt++;
    }
    for(int i=0;i<n && cnt>0;i++) {
        int k = cnt>=b[i] ? b[i] : cnt;
        curr = prev->next;
        next = curr->next;
        if(k==0) continue;
        for(int i=1;i<k;i++) {
            curr->next = next->next;
            next->next = prev->next;
            prev->next = next;
            next = curr->next;
        }
        prev = curr;
        cnt -= k;
    }
    return temp->next;
}