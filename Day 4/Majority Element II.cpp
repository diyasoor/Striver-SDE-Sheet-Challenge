#include <bits/stdc++.h> 
vector<int> majorityElementII(vector<int> &arr)
{
    unordered_map<int,int> map;
    int n = arr.size();
    vector<int> ans;
    for(int x:arr)
        map[x]++;  
    for(auto x: map) {
        if(x.second > (n/3)) 
            ans.push_back(x.first);
    }
    return ans;
}