/* Recursion T.C=O(N*M) with auxilliary Stack space*/
int dfs(vector<vector<int>>& grid, int i,int j) {
        
    if(i==grid.size()-1 && j==grid[0].size()-1) return grid[i][j];
    if(i>=grid.size() || j>=grid[0].size()) return INT_MAX;

    return grid[i][j] + min(dfs(grid,i+1,j),dfs(grid,i,j+1)); 
}
int minSumPath(vector<vector<int>>& grid) {
    return dfs(grid,0,0);
}

/* Memoization T.C=O(N*M) S.C=O(N*M) with ASS*/
#include<climits>
int dfs(vector<vector<int>>& grid, int i,int j,vector<vector<int>>& dp) {
        
    if(i==grid.size()-1 && j==grid[0].size()-1) return dp[i][j] = grid[i][j];
    if(i>=grid.size() || j>=grid[0].size()) return INT_MAX;

    if(dp[i][j]!=-1) return dp[i][j];
    return dp[i][j] = grid[i][j] + min(dfs(grid,i+1,j,dp),dfs(grid,i,j+1,dp));
}
int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
    return dfs(grid,0,0,dp);
}
