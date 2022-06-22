#include<algorithm>
string longestCommonPrefix(vector<string> &arr, int n)
{
    // Write your code here
    sort(arr.begin(),arr.end());
    string ans = "";
    for(int i=0;i<arr[0].size();i++) {
        if(arr[0][i]==arr[n-1][i]) {
            ans += arr[0][i];
        }
        else break;
    }
    return ans;
}


