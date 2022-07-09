#include<bits/stdc++.h>
class Node {
public:
    Node* links[2]; // 0 / 1
    bool containsKey(int bit) {
        return links[bit];
    }
    Node* getNext(int bit) {
        return links[bit];
    }
    void put(int bit,Node* node) {
        links[bit] = node;
    }
};
class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    void insert(int num) {
        Node* node = root;
        for(int i=31;i>=0;i--) {
            int bit = (num >> i) & 1; // bit set or not
            if(!node->containsKey(bit)) {
                node->put(bit,new Node());
            }
            node=node->getNext(bit);
        }
    }
    int getMax(int num) {
        Node* node = root;
        int maxNum = 0;
        for(int i=31;i>=0;i--) {
            int bit = (num >> i) & 1;
            // check if the opposite bit is present or not
            if(node->containsKey(1 - bit)) {
                maxNum = maxNum | (1 << i); // add it by doing left shift
                node = node->getNext(1 - bit); 
            }
            else {
                node = node->getNext(bit);
            }
        }
        return maxNum;
    }
};
// 
vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
    // queries[ [x(the no. with which we permorm Xor), a(the no. less than or equal to which the nos we are going to find from the array & will perform xor)] ]
    sort(arr.begin(), arr.end());
    int nq = queries.size();
    
    //          <a, x, query number>
    vector<pair<int,pair<int,int>>> offlineQueries;
    
    for(int i=0;i<nq;i++) {
        offlineQueries.push_back({queries[i][1], {queries[i][0], i}});
    }
    
    // sort wrt 'a'    // T.C: O(Q log Q)
    sort(offlineQueries.begin(),offlineQueries.end());
    
    vector<int> ans(nq, 0);
    Trie trie;
    int index = 0;
    // T.C = O(Q * 32 + N * 32)
    for(int i=0;i<nq;i++) {
        int ai = offlineQueries[i].first;
        int xi = offlineQueries[i].second.first;
        int qi = offlineQueries[i].second.second;
        while(index < arr.size() && arr[index] <= ai) {
            trie.insert(arr[index]);
            index++;
        }
        if(index==0) ans[qi]=-1;
        else ans[qi] = trie.getMax(xi);
    }
    return ans;
    
}