#include <bits/stdc++.h> 
int merge(vector<int> &arr, int s,int mid,int e) {
    int cnt = 0;
    int j = mid + 1;
    for(int i=s;i<=mid;i++) {
        while(j<=e && arr[i] > (2 * (long)arr[j])) {
            j++;
        }
        cnt += (j - (mid + 1));
    }
    vector<int> temp;
    int l = s, r = mid + 1;
    while(l <= mid && r <=e) {
        if(arr[l]<=arr[r]) {
            temp.push_back(arr[l]);
            l++;
        }
        else {
            temp.push_back(arr[r]);
            r++;
        }
    }
    while(l<=mid) {
        temp.push_back(arr[l]);
        l++;
    }
    while(r<=e) {
        temp.push_back(arr[r]);
        r++;
    }
    for(int i=s;i<=e;i++) {
        arr[i] = temp[i - s];
    }
    return cnt;
}
int mergeSort(vector<int>& arr,int s,int e) {
    if(s>=e) return 0;
    int cnt = 0;
    int mid = (s+e)/2;
    cnt += mergeSort(arr,s,mid);
    cnt += mergeSort(arr,mid+1,e);
    cnt += merge(arr,s,mid,e);
    return cnt;
}
int reversePairs(vector<int> &arr, int n){
    return mergeSort(arr,0,n-1);
}