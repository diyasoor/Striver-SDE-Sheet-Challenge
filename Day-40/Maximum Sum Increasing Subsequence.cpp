#include<bits/stdc++.h>
// Tabulation
int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
	// Write your code here
    vector<int> dp(rack.begin(),rack.end());
    
    for(int i=n-1;i>=0;i--) {
        for(int j=i+1; j<n;j++) {
            if(rack[i] < rack[j]) {
                dp[i] = max(dp[i], rack[i] + dp[j]);
            }
        }
    }
    return *max_element(dp.begin(),dp.end());
}