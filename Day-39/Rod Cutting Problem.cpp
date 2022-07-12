int f(vector<int> &p,int ind, int rod,vector<vector<int>> &dp) {
    if(ind==0) return rod * p[0];
    if(dp[ind][rod]!=-1) return dp[ind][rod];
    int notTake = f(p,ind-1,rod,dp);
    int take=0;
    int currRod = ind+1;
    if(currRod <= rod) take = p[ind] + f(p,ind,rod - currRod,dp);
    return dp[ind][rod] = max(take,notTake);
}
int cutRod(vector<int> &price, int n)
{
	// Write your code here.
    vector<vector<int>> dp(n, vector<int>(n+1, -1));
    return f(price,n-1,n,dp);
}
