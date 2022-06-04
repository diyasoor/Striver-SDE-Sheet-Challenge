#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &permutation, int n)
{
    int i,j;
    for(j=n-2;j>=0;j--) {
        if(permutation[j] < permutation[j+1]) {
            break;
        }
    }
    if(j<0) {
        reverse(permutation.begin(),permutation.end());
        return permutation;
    }
    for(i = n - 1; i>=0;i--) {
        if(permutation[i] > permutation[j]) {
            break;
        }
    }
    swap(permutation[i], permutation[j]);
    reverse(permutation.begin() + j + 1, permutation.end());
    return permutation;
}