void dfs(int** arr, int i, int j, int n, int m, int dir[][8]) {
    if(i<0 || j<0 || i>=n || j>=m || arr[i][j]!=1) return;
    
    arr[i][j]=2;
    
    for(int k=0;k<8;k++) {
        int ni = i + dir[k][0];
        int nj = j + dir[k][1];
        
        dfs(arr,ni,nj,n,m,dir);
    }
}
int getTotalIslands(int** arr, int n, int m)
{
   // Write your code here.
    int totalIslands = 0;
    
    int dir[8][8] = {{1,0},{0,1},{-1,0},{0,-1},{-1,-1},{1,1},{-1,1},{1,-1}};
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(arr[i][j]==1) {
                dfs(arr,i,j,n,m,dir);
                totalIslands++;
            }
        }
    }
    return totalIslands;
}
