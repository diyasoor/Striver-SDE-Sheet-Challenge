#include <bits/stdc++.h> 
vector<vector<int>> pairSum(vector<int> &arr, int s){
    vector<vector<int>> res;
    for(int i=0;i<arr.size();i++) {
        for(int j=i+1;j<arr.size();j++) {
            if(arr[i]+arr[j] == s) {
                vector<int> v;
                v.push_back(min(arr[i],arr[j]));
                v.push_back(max(arr[i],arr[j]));
                res.push_back(v);
            }
        }
    }
    sort(res.begin(),res.end());
    return res;
}