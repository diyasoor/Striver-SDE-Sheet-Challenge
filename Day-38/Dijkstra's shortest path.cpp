vector<int> dijkstra(vector<vector<int>> &vec, int V, int E, int S) {
    // Write your code here.
    vector<pair<int,int>> adj[V+1];
    for(int i=0;i<E;i++) {
        int u=vec[i][0];
        int v=vec[i][1];
        int w=vec[i][2];
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> dist(V, INT_MAX);

    dist[S] = 0;
    pq.push(make_pair(0,S)); // distance, node from

    while(!pq.empty()) {
        int dis = pq.top().first;
        int prevNode = pq.top().second;
        pq.pop();

        vector<pair<int,int>>::iterator it;
        for(it=adj[prevNode].begin(); it!=adj[prevNode].end(); it++) {
            int nextNode = it->first;
            int nextDist = it->second;
            if(dist[nextNode] > (dist[prevNode] + nextDist)) {
                dist[nextNode] = dist[prevNode] + nextDist;
                pq.push({dist[nextNode], nextNode});
            }
        }
    }
    return dist;
}
