vector<int> stringMatch(string &str, string &pat) {
    // Write your code here
    int strLen=str.length(), patLen=pat.length();
    vector<int> ans;
    for(int i=0;i<=strLen-patLen;i++) {
        int t=0,cnt=0;
        for(int j=i;j<i+patLen;j++) {
            if(str[j]==pat[t]) cnt++;
            t++;
        }
        if(cnt==patLen) ans.push_back(i);
    }
    return ans;
}
