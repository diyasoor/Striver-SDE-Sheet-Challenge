bool isCycle(int node,vector<int> adj[], vector<int> &vis, vector<int> &inSt) {
    vis[node] = 1;
    inSt[node] = 1;
    for(auto nbr: adj[node]) {
        if(!vis[nbr]) {
            if(isCycle(nbr,adj,vis,inSt)) return true;
        }
        else if(inSt[nbr]) return true;
    }
    inSt[node] = 0;
    return false;
}

int detectCycleInDirectedGraph(int V, vector < pair < int, int >> & edges) {
  // Write your code here.
    vector<int> adj[V+1];
    for(int i=0;i<edges.size();i++) {
        adj[edges[i].first].push_back(edges[i].second);
    }
    vector<int> visited(V+1,0);
    vector<int> inStack(V+1,0);
    for(int i=1;i<V;i++) {
        if(!visited[i] && isCycle(i,adj,visited,inStack)) {
            return 1;
        }
    }
    return 0;
}