#include <bits/stdc++.h> 
int findIntersection(Node *firstHead, Node *secondHead)
{
    Node *f = firstHead;
    Node *s = secondHead;
    while(f!=s) {
        f = !f ? secondHead : f->next;
        s = !s ? firstHead : s->next;
    }
    return !f ? -1 : f->data;
}