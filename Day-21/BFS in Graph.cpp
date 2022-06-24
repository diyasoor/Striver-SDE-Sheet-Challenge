#include<bits/stdc++.h>
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    // Write your code here
    vector<int> adj[vertex];
    for(int i=0;i<edges.size();i++) {
        adj[edges[i].first].push_back(edges[i].second);
        adj[edges[i].second].push_back(edges[i].first);
    }
    vector<int> visited(vertex,0);
    vector<int> ans;    

    for(int i=0;i<vertex;i++) {
        if(!visited[i]) {
            queue<int> q;
            q.push(i);
            visited[i] = 1;
            sort(adj[i].begin(),adj[i].end());
            while(!q.empty()) {
                int temp = q.front();
                q.pop();
                ans.push_back(temp);
                for(auto nbr: adj[temp]) {
                    if(!visited[nbr]) {
                        q.push(nbr);
                        visited[nbr] = 1;
                    }
                }
            }
        }
    }
    
    return ans;
    
}