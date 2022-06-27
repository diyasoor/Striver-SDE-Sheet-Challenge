bool isCycle(int node,vector<int> adj[], vector<int> &vis, int parent) {
    vis[node] = 1;
    for(auto nbr: adj[node]) {
        if(!vis[nbr]) {
            if(isCycle(nbr,adj,vis,node)) return true;
        }
        else if(nbr!=parent) return true;
    }
    return false;
}
string cycleDetection (vector<vector<int>>& edges, int V, int E)
{
    // Write your code here.
    vector<int> adj[V+1];
    for(int i=0;i<E;i++) {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    vector<int> vis(V+1,0);
    for(int i=1;i<V;i++) {
        if(!vis[i] && isCycle(i,adj,vis,-1)) {
            return "Yes";
        }
    }
    return "No";
}
