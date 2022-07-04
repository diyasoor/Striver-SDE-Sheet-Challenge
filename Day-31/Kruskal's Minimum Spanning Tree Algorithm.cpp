#include<algorithm>
bool cmp(vector<int> a, vector<int> b) {
    return a[2] < b[2];
}
int findParent(int node,vector<int> &parent) {
    if(node==parent[node]) 
        return node;
    // path compression
    return parent[node] = findParent(parent[node],parent);
}

void unionFind(int u, int v,vector<int> &parent, vector<int> &rank) {
    u = findParent(u,parent);
    v = findParent(v,parent);
    
    if(rank[u] > rank[v]) {
        parent[v] = u;
    }
    else if(rank[v] > rank[u]) {
        parent[u] = v;
    }
    else {
        parent[v] = u;
        rank[u]++;
    }
}
int kruskalMST(int V, int E, vector<vector<int>> &g) {
	// Write your code here.
    sort(g.begin(), g.end(),cmp);
    
    vector<int> rank(V+1, 0);
    vector<int> parent(V+1, 0);
    for(int i=1;i<=V;i++) {
        parent[i] = i;
    }
    
    int cost=0;
    for(auto it:g) {
        if(findParent(it[0], parent)!=findParent(it[1], parent)) {
            cost += it[2];
            unionFind(it[0], it[1], parent, rank);
        }
    }
    return cost;
}