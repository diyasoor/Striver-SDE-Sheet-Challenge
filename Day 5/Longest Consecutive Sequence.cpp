#include <bits/stdc++.h> 
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    unordered_set<int> s;
    int longest = 1;
    if(n==0) return 0;
    for(auto x:arr) {
        s.insert(x);
    }
    for(int num: arr) {
        int parent = num - 1;
        // not present in the set 
        if(s.find(parent)==s.end()) {
            int next = num + 1;
            int cnt = 1;
            // present in the set
            while(s.find(next)!=s.end()) {
                next++; cnt++;
            }
            longest = max(longest,cnt);
        }
    }
    return longest;
}