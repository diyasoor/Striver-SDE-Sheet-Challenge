#include<unordered_set>
void findPath(int idx,vector<string>& ans,string s,string output,unordered_set<string> set) {
    if(idx==s.size()) {
        output.pop_back(); // remove the trailing space
        ans.push_back(output);
        return;
    }
    string str="";
    for(int i=idx;i<s.size();i++) {
        str.push_back(s[i]);
        if(set.find(str)!=set.end()) {
            findPath(i+1,ans,s,output+str+" ",set);
        }
    }
}
vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    // Write your code here
    unordered_set<string> set;
    for(auto word: dictionary) {
        set.insert(word);
    }
    vector<string> ans;
    findPath(0,ans,s,"",set);
    return ans;
}