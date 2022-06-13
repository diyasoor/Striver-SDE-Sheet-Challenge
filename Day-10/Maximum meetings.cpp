#include<algorithm>
class meetings {
public:
    int begin;
    int finish;
    int index;
};
bool static comp(meetings m1, meetings m2) {
    if(m1.finish < m2.finish) return true;
    else if(m1.finish > m2.finish) return false;
    else if(m1.index < m2.index) return true;
    return false;
}
vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    int n = start.size();
    meetings m[n];
    for(int i=0;i<n;i++) {
        m[i].begin = start[i];
        m[i].finish = end[i];
        m[i].index = i+1;
    }

    sort(m, m+n,comp);

    vector<int> ans;
    int limit = m[0].finish;
    ans.push_back(m[0].index);
    
    for(int i=1;i<n;i++) {
        if(m[i].begin > limit) {
            ans.push_back(m[i].index);
            limit = m[i].finish;
        }    
    }
    return ans;
}