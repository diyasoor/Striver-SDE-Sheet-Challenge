#include<queue>
vector<int> slidingWindowMaximum(vector<int> &nums, int &k)
{
    int n = nums.size();
    vector<int> ans;
    deque<int> dq;
    for(int i=0;i<n;i++) {
        // check out of boundary elements
        if(!dq.empty() && dq.front()==i-k) dq.pop_front();
        // check elements if in decreasing order or not
        while(!dq.empty() && nums[i] >= nums[dq.back()]) dq.pop_back();
        
        dq.push_back(i);
        if(i >= k-1) ans.push_back(nums[dq.front()]);
    }
    return ans;
}