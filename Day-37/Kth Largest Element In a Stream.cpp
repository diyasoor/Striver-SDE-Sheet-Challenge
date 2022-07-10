#include<queue>
class Kthlargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int K;
    Kthlargest(int k, vector<int> &arr) {
       // Write your code here.
        K = k;
        for(int x:arr) pq.push(x);
    }

    void add(int num) {
        // Write your code here.
        pq.push(num);
    }

    int getKthLargest() {
       // Write your code here.
        while(pq.size() > K) pq.pop();
        return pq.top();
    }

};