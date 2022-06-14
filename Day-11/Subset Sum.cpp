void findSubsetSum(vector<int> &num,int idx,int sum,int n,vector<int> &ans) {
    if(idx==n) {
        ans.push_back(sum);
        return;
    }
    //pick
    findSubsetSum(num,idx+1,sum+num[idx],n,ans);
    //not pick
    findSubsetSum(num,idx+1,sum,n,ans);
}
vector<int> subsetSum(vector<int> &num)
{
    int n=num.size();
    vector<int> ans;
    findSubsetSum(num,0,0,n,ans);
    sort(ans.begin(),ans.end());
    return ans;
}