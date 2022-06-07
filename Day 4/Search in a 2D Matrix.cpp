#include <bits/stdc++.h> 
#include <vector>

bool findTargetInMatrix(vector < vector < int >> & mat, int m, int n, int target) {
    if(m==0) return false;
    int s=0,e=(m * n) - 1;
    while(s<=e) {
        int mid = (s + e)/2;
        if(mat[mid/n][mid%n]==target) return true;
        if(mat[mid/n][mid%n] < target) s = mid + 1;
        else e = mid - 1;
    }
    return false;
}