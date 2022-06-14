#include<algorithm>
void generateSubsets(vector<int>& arr,vector<int> &temp,vector<vector<int>> &ans,int idx,int n) {
    if(idx==n) {
        ans.push_back(temp);
        return;
    }
    // pick
    temp.push_back(arr[idx]);
    generateSubsets(arr,temp,ans,idx+1,n);
    // not pick backtrack
    temp.pop_back();
    while(idx+1 < n && arr[idx]==arr[idx+1]) idx++;
    generateSubsets(arr,temp,ans,idx+1,n);
}
vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    vector<vector<int>> ans;
    vector<int> temp;
    sort(arr.begin(),arr.end());
    generateSubsets(arr,temp,ans,0,n);
    sort(ans.begin(),ans.end());
    return ans;
}