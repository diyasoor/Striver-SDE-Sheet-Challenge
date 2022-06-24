#include<bits/stdc++.h>
int f(int i,int j,string &s, string &t,vector<vector<int>> &dp) {
    // base case
    if(i<0 || j<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    // matched
    if(s[i]==t[j])
        return dp[i][j] = 1 + f(i-1,j-1,s,t,dp);
    // not matched
    return dp[i][j] = max(f(i-1,j,s,t,dp),f(i,j-1,s,t,dp));
}
int lcs(string s, string t)
{
	//Write your code here
    int n=s.size(), m=t.size();
    vector<vector<int>> dp(n,vector<int>(m,-1));
    return f(n-1,m-1,s,t,dp);
}