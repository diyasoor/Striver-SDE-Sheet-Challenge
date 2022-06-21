#include<algorithm>
#include<queue>
#include<set>
class details {
    public:
     int val, idx, jdx;
};
struct cmp {
    bool operator()(details a,details b) {
        return a.val < b.val;
    }
};
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
	// Write your code here.
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    
    priority_queue<details, vector<details>, cmp> pq;
    set<pair<int,int>> s;
    vector<int> ans;
 
    pq.push({a[n-1]+b[n-1], n-1,n-1});
    s.insert({n-1,n-1});
    
    while(k--) {
        details temp=pq.top();
        pq.pop();
        int element = temp.val;
        int i = temp.idx, j = temp.jdx;
        ans.push_back(element);
        
        if(i-1 >= 0 && s.count({i-1,j})==0) {
            pq.push({a[i-1]+b[j], i-1, j});
            s.insert({i-1,j});
        }
        if(j-1 >= 0 && s.count({i,j-1})==0) {
            pq.push({a[i] + b[j-1], i, j-1});
            s.insert({i,j-1});
        }
    }
    return ans;
}