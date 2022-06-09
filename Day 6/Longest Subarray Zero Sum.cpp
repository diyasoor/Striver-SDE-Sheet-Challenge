#include <bits/stdc++.h> 
#include <unordered_map>
int LongestSubsetWithZeroSum(vector < int > arr) {
    int sum=0,maxLen = 0;
    unordered_map<int,int> map;
    for(int i=0;i<arr.size();i++) {
        sum += arr[i];
        if(sum==0) maxLen = i + 1;
        else {
            if(map.find(sum)!=map.end()) {
                maxLen = max(maxLen, i - map[sum]);
            }
            else map[sum] = i;
        }
    }
    return maxLen;
}