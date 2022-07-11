struct node{
    int u,v,w;
    node(int u,int v,int w) {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};
int bellmonFord(int V, int E, int src, int dest, vector<vector<int>> &edges) {
    // Write your code here.
    int inf=1000000000;
    vector<node> adj;
    for(int i=0;i<E;i++) {
        int u=edges[i][0];
        int v=edges[i][1];
        int w=edges[i][2];
        adj.push_back(node(u,v,w));
    }
    vector<int> dist(V+1,inf);
    dist[src]=0;
  
    for(int i=1;i<=V-1;i++) {
        for(auto it:adj) {
            if(dist[it.u]!=inf && (dist[it.u] + it.w) < dist[it.v]) {
                dist[it.v] = dist[it.u] + it.w;
            }
        }
    }
  
    return dist[dest];
}