#include<bits/stdc++.h>

void dfs(int node, stack<int> &st, vector<int> &vis, vector<int> adj[]) {
    vis[node] = 1;
    for(auto nbr: adj[node]) {
        if(!vis[nbr]) {
            dfs(nbr, st, vis, adj);
        }
    }
    st.push(node);
}
void revDFS(int node, vector<int> &vis, vector<int> transpose[], vector<int> &v) {
    v.push_back(node);
    vis[node] = 1;
    for(auto nbr: transpose[node]) {
        if(!vis[nbr]) {
            revDFS(nbr,vis,transpose,v);
        }
    }
}
// T.C = O(N+E)
// S.C = O(N+E) (to make transpose of the graph) + O(N) (for visited array) + O(N) (for the stack)
vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    // Write your code here.
    vector<vector<int>> ans;
    vector<int> adj[n];
    for(int i=0;i<edges.size();i++) {
        adj[edges[i][0]].push_back(edges[i][1]);
    }
    
    // step:1 Topological Sort, Sort all the nodes in order of their finishing time
    // DFS topo sort takes O(N+E) T.C
    stack<int> st;
    vector<int> visited(n,0);
    for(int i=0;i<n;i++) {
        if(!visited[i]) {
            dfs(i, st, visited, adj);
        }
    }
    // step:2 Transpose the graph
    // T.C = O(N+E)
    vector<int> transpose[n];
    for(int i=0;i<n;i++) {
        visited[i] = 0;
        for(auto nbr: adj[i]) {
            transpose[nbr].push_back(i);
        }
    }
    // step:3 Do DFS according to their finishing time
    //T.C: O(N+E)
    while(!st.empty()) {
        int node = st.top();
        st.pop();
        if(!visited[node]) {
            vector<int> v;
            revDFS(node,visited,transpose,v);
            ans.push_back(v);
        }
    }
    return ans;
}