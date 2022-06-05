#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
    long long sum=0, maxSum=0;
    for(int i=0;i<n;i++) {
        sum += (long long)arr[i];
        maxSum = max(sum,maxSum);
        if(sum<0) sum=0;
    }
    return maxSum;
}