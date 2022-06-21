#include<unordered_map>
#include<algorithm>
bool cmp(pair<int,int> a, pair<int,int> b) {
    return a.second > b.second;
}
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    // Write your code here.
    unordered_map<int,int> map;
    for(auto x:arr) map[x]++;
    vector<pair<int,int>> vec;
    for(auto m:map) {
        vec.push_back(make_pair(m.first,m.second));
    }
    sort(vec.begin(),vec.end(), cmp);
    vector<int> ans;
    for(int i=0;i<k;i++) {
        ans.push_back(vec[i].first);
    }
    sort(ans.begin(),ans.end());
    return ans;
}