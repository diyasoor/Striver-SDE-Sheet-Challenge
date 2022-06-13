#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	vector<vector<int>> ans;
    sort(arr.begin(),arr.end());
    for(int i=0;i<n-2;i++) {
        // for avoiding duplicate elements 
        if(i==0 || (i>0 && arr[i]!=arr[i-1])) {
            int l=i+1,r=n-1, sum = K-arr[i];
            while(l<r) {
                if(arr[l] + arr[r]==sum) {
                    ans.push_back({arr[i], arr[l], arr[r]});
                    while(l < r && arr[l]==arr[l+1]) l++;
                    while(l < r && arr[r]==arr[r-1]) r--;
                    l++; r--;
                }
                else if(arr[l] + arr[r] < sum) l++;
                else r--;
            }
        }
    }
    return ans;
}