int maxProfit(vector<int> &pft, vector<int> &wt, int n, int w)
{
	// Write your code here
	int dp[n+1][w+1];
	
	for(int i=0;i<=n;i++) {
		for(int j=0;j<=w;j++) {
			if(i==0 || j==0) dp[i][j]=0;
			else if(wt[i-1] > j) dp[i][j] = dp[i-1][j]; // we are gonna exclude it
			else if(wt[i-1] <= j) dp[i][j] = max(dp[i-1][j], pft[i-1] + dp[i-1][j - wt[i-1]]);
		}
	} 
	return dp[n][w];
}