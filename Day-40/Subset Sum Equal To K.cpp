// Memoization
bool f(vector<int> &arr, int i,int k, vector<vector<int>> &dp) {
    if(k==0) return true;
    if(i<0 || k<0) return false;
    if(dp[i][k]!=-1) return dp[i][k];
    bool take = f(arr,i-1,k-arr[i],dp);
    bool notTake = f(arr,i-1,k,dp);
    return dp[i][k] = (take||notTake);
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    int sum=0;
    vector<vector<int>> dp(n,vector<int>(k+1,-1));
    return f(arr,n-1,k,dp);
}