#include<bits/stdc++.h>
struct Node {
    int key, val, cnt;
    Node *next, *prev;
    Node(int k,int v) {
        key = k;
        val = v;
        cnt = 1; // freq cnt
    }
};
struct List {
    int size;
    Node *head, *tail;
    List() {
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    void addFront(Node *newNode) {
        Node *temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
        size++;
    }
    void deleteNode(Node *curNode) {
        Node *prevNode = curNode->prev;
        Node *nextNode = curNode->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        size--;
    }
};
class LFUCache {
    unordered_map<int, Node*> keyNodeMap;
    unordered_map<int, List*> freqListMap;
    int maxSize, minFreq, curSize;
public:
    LFUCache(int capacity)
    {
        // Write your code here.
        maxSize = capacity;
        minFreq = 0, curSize = 0;
    }
    void updateFreqListMap(Node *node) {
        keyNodeMap.erase(node->key);
        freqListMap[node->cnt]->deleteNode(node);
        // so as it was the list with minFreq and now deleted
        // so size==0 so now minFreq will increase
        if(node->cnt==minFreq && freqListMap[node->cnt]->size==0) {
            minFreq++;
        }
        
        List *nextFreqList = new List();
        if(freqListMap.count(node->cnt + 1)!=0) {
            nextFreqList = freqListMap[node->cnt + 1];
        }
        node->cnt += 1;
        nextFreqList->addFront(node);
        
        keyNodeMap[node->key] = node;
        freqListMap[node->cnt] = nextFreqList;
    }
    int get(int k)
    {
        // Write your code here.
        if(keyNodeMap.count(k)!=0) {
            Node *node = keyNodeMap[k];
            int data = node->val;
            updateFreqListMap(node);
            return data;
        }
        return -1;
    }

    void put(int k, int v)
    {
        // Write your code here.
        if(maxSize==0) return;
        // present in hashmap only update the value
        // update the frequency count
        if(keyNodeMap.count(k)!=0) {
            Node *node = keyNodeMap[k];
            node->val = v;
            updateFreqListMap(node);
        }
        else {
            if(curSize==maxSize) {
                List *list = freqListMap[minFreq];
                keyNodeMap.erase(list->tail->prev->key);
                freqListMap[minFreq]->deleteNode(list->tail->prev);
                curSize--;
            }
            // not present, new key-value pair
            curSize++;
            minFreq = 1;
            List* newList = new List();    // creation of head and tail node
            // if already this frequency nodes are exist
            if(freqListMap.count(minFreq)!=0) {
                // rewrite the newly created list with the already present list
                newList = freqListMap[minFreq];
            }
            Node *newNode = new Node(k,v); // node creation
            newList->addFront(newNode);    // add it after head so that we can make a note of the LRU key-value
            // add it in both the hashmaps 
            keyNodeMap[k] = newNode;      
            freqListMap[minFreq] = newList;
        }
    }
};
