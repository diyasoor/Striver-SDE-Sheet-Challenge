#include<algorithm>
void calculate(int idx, vector<int>& nums, int target, vector<vector<int>>& ans, vector<int>& v) {
    if(target==0) {
        ans.push_back(v);
        return;
    }
    
    for(int i=idx;i<nums.size();i++) {
        if(i > idx && nums[i-1]==nums[i]) continue;
        if(nums[i] > target) break;
        v.push_back(nums[i]);
        calculate(i+1,nums,target-nums[i],ans,v);
        v.pop_back();
    }
    
}
vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
	// Write your code here.
    vector<vector<int>> ans;
    vector<int> v;
    sort(arr.begin(),arr.end());
    calculate(0, arr, target, ans, v);
    return ans;
}
