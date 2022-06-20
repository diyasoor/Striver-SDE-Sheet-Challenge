#include<queue>
#include<vector>
#define pair pair<int, pair<int, int>>
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here. 
    priority_queue<pair, vector<pair>, greater<pair>> pq;
    
    // init priority queue
    for(int i=0;i<k;i++) {
        int element = kArrays[i][0];
        // element, array_index, element_index
        pq.push(make_pair(element,make_pair(i, 0)));
    }
    vector<int> ans;
    while(!pq.empty()) {
        auto top = pq.top(); 
        int element = top.first;
        int arr_idx = top.second.first;
        int ele_idx = top.second.second;
        pq.pop();
        
        ans.push_back(element);
        
        if(ele_idx + 1 < kArrays[arr_idx].size()) {
            int nextElement = kArrays[arr_idx][ele_idx+1];
            pq.push(make_pair(nextElement, make_pair(arr_idx, ele_idx+1)));
        }
    }
    return ans;
}
