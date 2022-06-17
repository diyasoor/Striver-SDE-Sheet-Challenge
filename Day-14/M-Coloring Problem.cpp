bool canColor(int node,vector<vector<int>> &mat,vector<int>& color, int col, int n) {
    for(int adj=0;adj<n;adj++) {
        if(adj!=node && mat[node][adj] && color[adj]==col) return false;
    }
    return true;
}
bool putColor(int node,vector<vector<int>> &mat,vector<int>& color, int m, int n) {
    // base case
    if(node==n) return true;
    // recursive case
    for(int i=1;i<=m;i++) {
        if(canColor(node,mat,color,i,n)) {
            color[node] = i;
            if(putColor(node+1,mat,color,m,n)==true) return true;
            color[node] = 0;
        }
    }
    return false;
} 
string graphColoring(vector<vector<int>> &mat, int m) {
    // Write your code here
    int n = mat.size();
    vector<int> color(n,0);
    int node = 0;
    if(putColor(node,mat,color,m,n)) return "YES";
    else return "NO";
}