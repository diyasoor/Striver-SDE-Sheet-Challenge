#include <bits/stdc++.h> 
int subarraysXor(vector<int> &arr, int x)
{
    int n = arr.size();
    vector<int> prefix(n);
    prefix[0] = arr[0];

    for(int i=0;i<n;i++) {
        prefix[i] = prefix[i-1] ^ arr[i];
    }
    int cnt=0;
    unordered_map<int,int> map;
    for(int i=0;i<n;i++) {
        int xor1 = x ^ prefix[i];
        if(prefix[i]==x) cnt++;
        if(map.find(xor1) != map.end()) {
            cnt += map[xor1];
        }
        map[prefix[i]]++;
    }
    return cnt;
}