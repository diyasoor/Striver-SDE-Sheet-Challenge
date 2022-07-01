#include<bits/stdc++.h>
class LRUCache
{
public:
    class node {
        public: 
            int k;
            int v;
            node *next, *prev;
            node(int key, int value) {
                k = key;
                v = value;
            }
    };
    node *head = new node(-1,-1);
    node *tail = new node(-1,-1);
    
    int capacity;
    unordered_map<int,node*> m;
    
    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void addNode(node *newNode) {
        node *temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }
    
    void deleteNode(node *curNode) {
        node *prevNode = curNode->prev;
        node *nextNode = curNode->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        // delete(curNode);
    }
    int get(int key)
    {
        // Write your code here
        if(m.count(key)!=0) {
            node *it = m[key];
            int val = it->v;
            m.erase(key);
            deleteNode(it);
            addNode(it);
            m[key] = head->next;
            return val;
        }
        return -1;
    }

    void put(int key, int value)
    {
        // Write your code here
        if(m.count(key)!=0) {
            node *it = m[key];
            m.erase(key);
            deleteNode(it);
        }
        if(m.size()==capacity) {
            m.erase(tail->prev->k); // delete from hashmap
            deleteNode(tail->prev);    // delete the node from DLL
        }
        addNode(new node(key,value));
        m[key] = head->next;
    }
};
