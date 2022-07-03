#include<queue>
bool check(int n, vector<int> adj[], vector<int> &color) {
    queue<int> q;
    q.push(n);
    color[n] = 1;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for(auto nbr:adj[node]) {
            if(color[nbr]==-1) {
                q.push(nbr);
                color[nbr] = 1 - color[node];
            }
            else if(color[nbr]==color[node]) return false;
        }
    }
    return true;
}
bool isGraphBirpatite(vector<vector<int>> &edges) {
	// Write your code here.
    int n=edges[0].size();
    vector<int> adj[n];
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(edges[i][j]==1) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    vector<int> color(n,-1);
    for(int i=0;i<n;i++) {
        if(color[i]==-1) {
            if(!check(i, adj, color)) {
                 return false;   
            }
        }
    }
    return true;
}