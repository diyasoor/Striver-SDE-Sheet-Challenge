// Recursion(T.C=Exponential) -> Memoization(T.C=O(N^3) with extra auxilliary space) ->Tabulation (T.C=O(N^3) with no extra auxilliary space) 
// int f(int i, int j, vector<int>&arr,  vector<vector<int>>& dp) {
//     if(i==j) return 0;
//     int minOp = INT_MAX;
//     if(dp[i][j]!=-1) return dp[i][j];
//     for(int k=i; k<j;k++) {
//         int steps = f(i,k,arr,dp) + f(k+1,j,arr,dp) + arr[i-1]*arr[k]*arr[j];
//         minOp = min(minOp, steps);
//     }
//     return dp[i][j] = minOp;
// }
int matrixMultiplication(vector<int> &arr, int N)
{
    // Write your code here.
    vector<vector<int>> dp(N,vector<int>(N,0));
    for(int i=N-1;i>=1;i--) {
        for(int j=i+1;j<N;j++) {
            int minOp = INT_MAX;
            for(int k=i; k<j;k++) {
                int steps = dp[i][k] + dp[k+1][j] + arr[i-1]*arr[k]*arr[j];
                minOp = min(minOp, steps);
            }
            dp[i][j] = minOp;
        }
    }
    return dp[1][N-1];
}