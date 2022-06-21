#include<queue>
void findMedian(int *arr, int n)
{
    // Write your code here
    int median = arr[0];
    priority_queue<int> leftHeap;  // maxheap
    priority_queue<int,vector<int>,greater<int>> rightHeap; // minheap
    
    leftHeap.push(median);
//     cout<<median<<" ";
    vector<int> ans;
    ans.push_back(median);
    for(int i=1;i<n;i++) {
        int num = arr[i];
        if(leftHeap.size()==rightHeap.size()) {
            if(num < median) {
                leftHeap.push(num);
                median = leftHeap.top();
            }
            else {
                rightHeap.push(num);
                median = rightHeap.top();
            }
        }        
        else if(leftHeap.size() > rightHeap.size()) {
            if(num < median) {
                rightHeap.push(leftHeap.top());
                leftHeap.pop();
                leftHeap.push(num);
            }
            else {
                rightHeap.push(num);
            }
            median = (leftHeap.top() + rightHeap.top()) / 2.0;
        }
        else {
            if(num < median) {
                leftHeap.push(num);
            }
            else {
                leftHeap.push(rightHeap.top());
                rightHeap.pop();
                rightHeap.push(num);
            }
            median = (leftHeap.top() + rightHeap.top()) / 2;
        }
//         cout<<median<<" ";
          ans.push_back(median);
    }
    for(int i=0;i<n;i++) {
        cout<<ans[i]<<" ";
    }
    return;
}