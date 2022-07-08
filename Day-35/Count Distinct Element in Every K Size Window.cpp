#include<unordered_map>
vector<int> countDistinctElements(vector<int> &arr, int k) 
{
    // Write your code here
	unordered_map<int,int> map;
    int n=arr.size();
    for(int i=0;i<k;i++) {
        map[arr[i]]++;
    }
    vector<int> ans;
    ans.push_back(map.size());
    for(int i=k;i<n;i++) {
        if(map[arr[i-k]]==1) {
            map.erase(arr[i-k]);
        }
        else {
            map[arr[i-k]]--;
        }
        map[arr[i]]++;
        ans.push_back(map.size());
    }
    return ans;
}
