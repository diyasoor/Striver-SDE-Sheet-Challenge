int kthLargest(vector<int>& arr, int size, int K)
{
	// Write your code here.
    priority_queue<int> pq;
    for(auto x:arr) pq.push(x);
    K=K-1;
    while(K--) pq.pop();
    return pq.top();
}