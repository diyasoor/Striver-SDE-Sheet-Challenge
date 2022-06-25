#include<bits/stdc++.h>
class Queue {
    stack<int> input,output;
    public:
    Queue() {}

    void enQueue(int val) {
        input.push(val);
    }

    int deQueue() {
        if(input.empty()) return -1;
        else {
             while(!input.empty()) {
                 output.push(input.top());
                 input.pop();
             }
             int x = output.top();
             output.pop();
             while(!output.empty()) {
                 input.push(output.top());
                 output.pop();
             }
            return x;
        }
    }

    int peek() {
        if(input.empty()) return -1;
        else {
            while(!input.empty()) {
                 output.push(input.top());
                 input.pop();
             }
            int x = output.top();
             while(!output.empty()) {
                 input.push(output.top());
                 output.pop();
             }
            return x;
        }  
    }

    bool isEmpty() {
        return input.empty();
    }
};