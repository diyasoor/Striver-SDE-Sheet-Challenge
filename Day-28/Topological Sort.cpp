#include<bits/stdc++.h>
void topoSort(int node, vector<int> &vis, stack<int> &s, vector<int> adj[]) {
    vis[node] =1;
    for(auto nbr: adj[node]) {
        if(!vis[nbr])
            topoSort(nbr,vis,s,adj);
    }
    s.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    vector<int> adj[v];
    for(int i=0;i<e;i++) {
        adj[edges[i][0]].push_back(edges[i][1]);
    }
    stack<int> s;
    vector<int> visited(v,0);
    // dfs 
    for(int i=0;i<v;i++) {
        if(!visited[i])
            topoSort(i,visited,s,adj);
    }
    vector<int> ans;
    while(!s.empty()) {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}