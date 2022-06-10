#include <bits/stdc++.h> 
Node *addTwoNumbers(Node *head1, Node *head2)
{
    Node *head3 = new Node(0);
    Node *start = head3;
    int carry = 0,sum=0;
    while(head1 && head2) {
        sum = head1->data + head2->data + carry;
        carry = sum/10;
        head3->next = new Node(sum%10);
        head1 = head1->next;
        head2 = head2->next;
        head3 = head3->next;
    }
    while(head1) {
        sum = head1->data + carry;
        carry = sum/10;
        head3->next = new Node(sum%10);
        head1 = head1->next;
        head3 = head3->next;
    } 
    while(head2) {
        sum = head2->data + carry;
        carry = sum/10;
        head3->next = new Node(sum%10);
        head2 = head2->next;
        head3 = head3->next;
    }
    if(carry) {
        head3->next = new Node(carry);
    }
    return start->next;
}