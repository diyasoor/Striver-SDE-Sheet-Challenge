bool isPalindrome(string s,int start,int end) {
    while(start<=end) {
        if(s[start]!=s[end]) return false;
        start++;
        end--;
    }
    return true;
}
void palPartition(int start,string s,vector<vector<string>>& ans,vector<string>& v) {
    if(start==s.size()) {
        ans.push_back(v);
        return;
    }
    for(int i=start;i<s.size();i++) {
        if(isPalindrome(s,start,i)) {
            v.push_back(s.substr(start,i - start + 1));
            palPartition(i+1,s,ans,v);
            v.pop_back();
        }
    }
}
vector<vector<string>> partition(string &s) 
{
    // Write your code here.
    vector<vector<string>> ans;
    vector<string> v;
    palPartition(0,s,ans,v);
    return ans;
}