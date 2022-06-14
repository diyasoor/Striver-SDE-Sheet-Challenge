void bfs(int i,int k,int n,vector<int>& arr,vector<vector<int>>& ans, vector<int> &v) {
    if(i>=n) {
        if(k==0) ans.push_back(v);
        return;
    }
    else {
        v.push_back(arr[i]);
        bfs(i+1,k-arr[i],n,arr,ans,v);
        v.pop_back();
        bfs(i+1,k,n,arr,ans,v);
    }
}
vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    // Write your code here.
    vector<vector<int>> ans;
    vector<int> v;
    bfs(0,k,n,arr,ans,v);
    return ans;
}