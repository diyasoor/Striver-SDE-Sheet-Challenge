#include<queue>
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
	// Write your code here.
    vector<int> ans;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for(auto x:arr) {
        maxHeap.push(x);
        minHeap.push(x);
    }
    int p = k-1; 
    k=k-1;
    while(k--) minHeap.pop();
    ans.push_back(minHeap.top());
    while(p--) maxHeap.pop();
    ans.push_back(maxHeap.top());
    
    return ans;
}