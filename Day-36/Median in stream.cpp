#include<bits/stdc++.h>
vector<int> findMedian(vector<int> &arr, int n){
	
	// Write your code here 
    priority_queue<int> left; //maxheap
    priority_queue<int, vector<int>, greater<int>> right; // minheap
    vector<int> ans;
    int median;
    for(int i=0;i<n;i++) {
        int num = arr[i];
        if(left.empty() && right.empty()) {
            left.push(num);
            median = num;
        }
        else if(left.size()==right.size()) {
            if(num < median) {
                left.push(num);
                median = left.top();
            }
            else {
                right.push(num);
                median = right.top();
            }
        }
        else if(left.size() < right.size()) {
            if(num < median) {
                left.push(num);
            }
            else {
                left.push(right.top());
                right.pop();
                right.push(num);
            }
            median = (left.top() + right.top()) / 2;
        }
        else {
            if(num > median) {
                right.push(num);
            }
            else {
                right.push(left.top());
                left.pop();
                left.push(num);
            }
            median = (left.top() + right.top()) / 2;
        }
        ans.push_back(median);
    }
    return ans;
}
