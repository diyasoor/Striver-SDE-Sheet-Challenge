// T.C = O(2^N x N)
// S.C = O(1)
vector<vector<int>> pwset(vector<int> v)
{
    //Write your code here
    vector<vector<int>> ans;
    int n = v.size();
    for(int num=0;num<(1<<n);num++) {
        vector<int> d;
        for(int i=0;i<n;i++) {
            // check if the bit is set or not set
            if((num & (1<<i))!=0) {
                d.push_back(v[i]);
            } 
        }
        ans.push_back(d);
    }
    return ans;
}