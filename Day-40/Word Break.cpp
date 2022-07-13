bool wordBreak(vector<string> & arr, int k, string &s) {
    // Write your code here.
    int n=s.size();
    vector<bool> dp(n+1,false);
    dp[n] = true;

    for(int i=n-1;i>=0;i--) {
        for(auto w: arr) {
            int curSize = i+w.size();
            if(curSize <= n && s.substr(i,w.size())==w) {
                dp[i] = dp[curSize];
            }
            if(dp[i]) break;
        }
    }
    return dp[0];
}