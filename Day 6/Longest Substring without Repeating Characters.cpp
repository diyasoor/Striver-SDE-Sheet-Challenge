#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
    int maxLen = 0,len =0;
    int left = 0, right = 0;
    unordered_map<char,int> map;
    while(right < input.size()) {
        char ch = input[right];
        if(map.find(ch)!=map.end() and map[ch] >= left) {
            left = map[ch] + 1;
            len = right - left;
        }
        map[ch] = right;
        len++;
        maxLen = max(maxLen, len);
        right++;
    }
    return maxLen;
}