#include<queue>
int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    // Write your code here. 
    int total=0, cnt=0, days=0;
    queue<pair<int,int>> q;
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(grid[i][j]!=0) total++;
            if(grid[i][j]==2) q.push({i,j});
        }
    }
    int dir[4][4] = {{1,0},{0,1},{-1,0},{0,-1}};
    
    while(!q.empty()) {
        int k = q.size();
        cnt += k;
        while(k--) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i=0;i<4;i++) {
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];

                if(nx<0 || nx>=n || ny<0 || ny>=m || grid[nx][ny]!=1) continue;

                grid[nx][ny] = 2;
                q.push({nx,ny});
            }
        }
        if(!q.empty()) days++;
    }
    return (total==cnt) ? days : -1;
}