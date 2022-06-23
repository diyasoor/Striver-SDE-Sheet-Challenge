#include<vector>
void dfs(int node, vector<int> &vis, vector<int> &ans,vector<int> adj[]) {
    vis[node] = 1;
    ans.push_back(node);
    for(auto nbr: adj[node]) {
        if(!vis[nbr]) {
            dfs(nbr,vis,ans,adj);
        }
    }
    return;
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    vector<int> adj[V];
    for(int i=0;i<E;i++) {
        int x=edges[i][0];
        int y=edges[i][1];
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> visited(V,0);
    vector<vector<int>> result;
    for(int i=0;i<V;i++) {
        vector<int> ans;
        if(!visited[i]) {
            dfs(i,visited,ans,adj);
        }
        if(ans.size()) result.push_back(ans);
    }
    
    return result;
}