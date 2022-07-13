#include<vector>
bool isPalindrome(int i,int j,string s) {
    while(i<=j) {
        if(s[i]!=s[j]) return false;
        i++, j--;
    }
    return true;
}
int f(int i,int n, string s, vector<int> &dp) {
    if(i==n) return 0;
    if(dp[i]!=-1) return dp[i];
    int minCost = INT_MAX;
    for(int j=i;j<n;j++) {
        if(isPalindrome(i,j,s)) {
            int cost = f(j+1,n,s,dp) + 1;
            minCost = min(minCost, cost);
        }
    }
    return dp[i] = minCost;
}
int palindromePartitioning(string str) {
    // Write your code here
    vector<int> dp(str.size(), -1);
    return f(0,str.size(),str,dp) - 1;
}
