#include <bits/stdc++.h> 
int findMajorityElement(int arr[], int n) {
	unordered_map<int,int> map;
    int val = floor(n/2);
    int ans = -1;
    for(int i=0;i<n;i++) {
        int x = arr[i];
        map[x]++;  
        if(map[x]>val) {
            ans = x;
            break;
        }
    }
    return ans;
}