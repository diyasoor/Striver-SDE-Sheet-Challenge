#include <bits/stdc++.h> 
bool isPalindrome(LinkedListNode<int> *head) {
    if(head==NULL or head->next==NULL) return true;
    LinkedListNode<int>* slow = head;
    LinkedListNode<int>* fast = head;
    // middle of linked list
    while(fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    // reverse the second half
    LinkedListNode<int> *prev= NULL;
    LinkedListNode<int> *curr=slow->next, *temp;
    while(curr!=NULL) {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    slow->next = prev;
    slow = slow->next;
    // check if the first and second half are equal or not
    LinkedListNode<int> *t =head;
    while(slow!=NULL) {
        if(t->data!=slow->data) return false;
        t = t->next;
        slow = slow->next;
    }
    return true;
}