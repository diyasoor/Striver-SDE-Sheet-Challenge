#include<bits/stdc++.h>
long f(int *a,int i,int v,vector<vector<long>> &dp) {
    if(i==0) {
        return (v % a[0] == 0);
    }
    if(dp[i][v]!=-1) 
        return dp[i][v];
    
    long notTake = f(a,i-1,v,dp);
    
    long take=0;
    if(a[i] <= v) take = f(a,i,v-a[i],dp);
    return dp[i][v] = notTake + take;
}
long countWaysToMakeChange(int *denominations, int n, int value)
{
    //Write your code here
    vector<vector<long>> dp(n, vector<long>(value+1, -1));
    return f(denominations,n-1,value,dp);
}