#include<bits/stdc++.h>
vector<int> nextGreater(vector<int> &arr, int n) {
    // Write your code here
    vector<int> v;
    stack<int> s;
    for(int i=arr.size()-1;i>=0;i--) {
        if(s.empty()) v.push_back(-1);
        else if(s.top() > arr[i]) v.push_back(s.top());
        else {
            // pop the stack until u find the greatest element
            while(!s.empty() && s.top()<=arr[i]) s.pop();
            if(s.empty()) v.push_back(-1);
            else if(s.top() > arr[i]) v.push_back(s.top());
        }
        s.push(arr[i]);
    }
    reverse(begin(v),end(v));
    return v;
}