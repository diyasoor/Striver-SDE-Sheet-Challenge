#include<algorithm>
class meetings {
public:
    int begin;
    int end;
    int index;
};
bool static comp(meetings m1, meetings m2) {
    if(m1.end < m2.end) return true;
    else if(m1.end > m2.end) return false;
    else if(m1.index < m2.index) return true;
    return false;
}
int maximumActivities(vector<int> &start, vector<int> &finish) {
    int n = start.size();
    meetings m[n];
    for(int i=0;i<n;i++) {
        m[i].begin = start[i];
        m[i].end = finish[i];
        m[i].index = i+1;
    }

    sort(m, m+n,comp);

    int ans=1;
    int limit = m[0].end;
    
    for(int i=1;i<n;i++) {
        if(m[i].begin >= limit) {
            ans++;
            limit = m[i].end;
        }    
    }
    return ans;
}