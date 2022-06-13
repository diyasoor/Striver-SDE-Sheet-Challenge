#include<algorithm>
bool comp(vector<int> j1,vector<int> j2) {
    return j1[1] > j2[1];
}
int jobScheduling(vector<vector<int>> &jobs)
{
    int n = jobs.size();
    sort(jobs.begin(),jobs.end(),comp);
    int maxDead = jobs[0][0];
    // getting the max deadline present in the 1st column of jobs
    for(int i=1;i<n;i++) {
        maxDead = max(maxDead, jobs[i][0]);
    }
    vector<int> arrange(maxDead+1,-1);
    int maxProfit = 0;
    for(int i=0;i<n;i++) {
        for(int j=jobs[i][0]; j>0;j--) {
            if(arrange[j]==-1) {
                arrange[j] = i;
                maxProfit += jobs[i][1];
                break;
            }
        }
    }
    return maxProfit;
}
