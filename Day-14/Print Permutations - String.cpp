void permute(int start, vector<string>&ans, string &s) {
    if(start==s.size()) {
        ans.push_back(s);
        return;
    }
    for(int i=start;i<s.size();i++) {
        swap(s[start],s[i]);
        permute(start+1,ans,s);
        swap(s[start],s[i]);
    }
}
vector<string> findPermutations(string &s) {
    // Write your code here.
    vector<string> ans;
    permute(0,ans,s);
    return ans;
}