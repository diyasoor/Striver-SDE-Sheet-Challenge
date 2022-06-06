#include <bits/stdc++.h> 
long long merge(long long *arr, long long *temp, int s, int e) {
    
    int i = s;
    int m = (s+e)/2;
    int j = m + 1;
    int k = s;
    long long cnt=0;
    
    while(i<=m and j<=e) {
        if(arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i++; k++;
        }
        else {
            temp[k] = arr[j];
            j++; k++;
            cnt += (m - i + 1);
        }
    }
    while(i<=m) temp[k++] = arr[i++];
    while(j<=e) temp[k++] = arr[j++];
    
    for(int idx=s; idx<=e;idx++) {
        arr[idx] = temp[idx];
    }
    return cnt;
}
long long mergeSort(long long *arr, long long *temp, int s,int e) {
    long long cnt=0;
    // base case
    if(s>=e) return cnt;
    
    // recursive case
    int mid = (s+e)/2;
    cnt += mergeSort(arr,temp,s,mid);
    cnt += mergeSort(arr,temp,mid+1,e);
    cnt += merge(arr,temp,s,e);
    return cnt;
}
long long getInversions(long long *arr, int n){
    int s=0,e=n-1;
    long long temp[n];
    return mergeSort(arr,temp,s,e);
}