bool findPattern(string p, string s)
{
    // Write your code here.
    vector<int> lps(p.size(),0);
    for(int i=1;i<p.size();i++) {
        int j = lps[i-1];
        while(j>0 && p[j]!=p[i]) {
            j = lps[j-1];
        }
        if(p[j]==p[i]) j++;
        lps[i] = j;
    }
    int i=0,j=0, cnt=0;
    while(i<s.length()) {
        if(s[i]==p[j]) {
            i++; j++;
        }
        else {
            if(j==0) i++;
            else j = lps[j-1];
        }
        if(j==p.length()) cnt++;
    }
    return cnt;
    
}