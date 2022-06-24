#include<bits/stdc++.h>
vector<int> calcLPS(string p) {
    int n=p.size();
    vector<int> lps(n,0);
    for(int i=1;i<n;i++) {
        int j = lps[i-1];
        while(j>0 && p[j]!=p[i]) {
            j = lps[j-1];
        }
        if(p[j]==p[i]) j++;
        lps[i] = j;
    }
    return lps;
}
int minCharsforPalindrome(string str) {
	// Write your code here.
	string rev = str;
    reverse(rev.begin(), rev.end());
    string concat = str + "#" + rev;

    vector<int> lps = calcLPS(concat);
    return str.size() - lps.back();
}
