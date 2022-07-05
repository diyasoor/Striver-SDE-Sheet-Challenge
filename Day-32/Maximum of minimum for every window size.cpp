#include<stack>
vector<int> maxMinWindow(vector<int> a, int n) {
    // Write your code here.
    
    vector<int> right(n), left(n);
    stack<int> st;
    
    for(int i=0;i<n;i++) {
        while(!st.empty() && a[st.top()] >= a[i]) {
            st.pop();
        }
        if(st.empty()) left[i] = -1;
        else left[i] = st.top();
        st.push(i);
    }
    
    while(!st.empty()) st.pop();
    
    for(int i=n-1;i>=0;i--) {
        while(!st.empty() && a[st.top()] >= a[i]) {
            st.pop();
        }
        if(st.empty()) right[i] = n;
        else right[i] = st.top();
        st.push(i);
    }
    vector<int> ans(n+1,INT_MIN);
    
    for(int i=0;i<n;i++) {
        
        int size = right[i] - left[i] - 1;
        ans[size] = max(ans[size], a[i]);
    }
    
    for(int i=n-1;i>=1;i--) {
        ans[i] = max(ans[i], ans[i+1]);
    }
    
    vector<int> res(ans.begin()+1, ans.end());
    return res;
}