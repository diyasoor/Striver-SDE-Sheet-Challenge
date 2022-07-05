#include<stack>
vector<int> findSpans(vector<int> &price) {
    // Write your code here.
    stack<pair<int,int>> st;
    vector<int> ans;
    for(int i=0;i<price.size();i++) {
        
        while(!st.empty() && price[i] >= st.top().first) {
            st.pop();
        }
        if(!st.empty() && st.top().first > price[i]) {
            ans.push_back(i - st.top().second);
        }
        else if(st.empty()) {
            ans.push_back(i+1);
        }
        st.push({price[i], i});
    }
    return ans;
}