#include<climits>
vector<pair<pair<int, int>, int>> calculatePrimsMST(int V, int E, vector<pair<pair<int, int>, int>> &g)
{
    // Write your code here.
    // node -> adj nodes, weights
    vector<pair<int,int>> adj[V+1];
    
    // creating the adjacency list
    for(int i=0;i<E;i++) {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    } 
    
    vector<int> parent(V+1,-1), weights(V+1,INT_MAX), MST(V+1,0);
    weights[1] = 0;
    parent[1] = -1;

    for(int edge=0; edge < V - 1; edge++) {
        int minWeight = INT_MAX, node;
        
        // finding the starting node with min weight 
        // which is not present in the MST
        for(int i=1;i<=V;i++) {
            if(!MST[i] && weights[i] < minWeight) {
                minWeight = weights[i];
                node = i;
            }   
        }
        MST[node] = 1;
        
        // finding neighbours with minimum weights
        for(auto x: adj[node]) {
            int nbr = x.first;
            int wei = x.second;
            if(!MST[nbr] && wei < weights[nbr]) {
                parent[nbr] = node;
                weights[nbr] = wei;
            }
        }
    }
    vector<pair<pair<int, int>, int>> ans;
    for(int i=2; i<=V; i++) {
        ans.push_back({{parent[i], i}, weights[i]});
    }
    return ans;
}
