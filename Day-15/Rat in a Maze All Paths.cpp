void pathSolve(int i,int j,vector<vector<int>> &m, int n,int dir[][2], vector<vector<int>>& ans,vector<vector<int>>& vis) {
    if(i==n-1 && j==n-1) {
        vector<int> v;
        for(int p=0;p<n;p++) {
            for(int q=0;q<n;q++) {
                v.push_back(vis[p][q]);
            }
        }
        ans.push_back(v);
        return;
    }
    for(int pos=0;pos<4;pos++) {
        int newi = i + dir[pos][0];
        int newj = j + dir[pos][1];
        if(newi>=0 && newj>=0 && newi<n && newj<n && vis[newi][newj]==0 && m[newi][newj]==1) {
            vis[newi][newj] = 1;
            pathSolve(newi,newj,m,n,dir,ans,vis);
            vis[newi][newj] = 0;
        }
    }
}
vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
  // Write your code here.
    vector<vector<int>> ans;
    if(n==0) return ans;
    vector<vector<int>> visited(n,vector<int>(n,0));
    int dir[4][2] = {{0,-1},{0,1},{-1,0},{1,0}};
    if(maze[0][0]==1) {
        visited[0][0] = 1;
        pathSolve(0,0,maze,n,dir,ans,visited);
    }
    return ans;
}