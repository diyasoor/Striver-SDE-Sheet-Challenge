#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){

    long *left = new long[n];
    long *right = new long[n];
    left[0] = arr[0];
    right[n-1] = arr[n-1];

    for(int i=1; i<n;i++) {
        left[i] = max(left[i-1],arr[i]);
        right[n-i-1] = max(right[n-i],arr[n-i-1]);
    }

    long water = 0;
    for(int i=0;i<n;i++) {
        water += min(left[i],right[i]) - arr[i];
    }
    return water;
}