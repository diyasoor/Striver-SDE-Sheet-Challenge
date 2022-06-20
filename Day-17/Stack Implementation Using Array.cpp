// Stack class.
class Stack {
    int *arr;
    int TOP;
    int size;
public:
    
    Stack(int capacity) {
        // Write your code here.
        size = capacity;
        TOP = -1;
        arr = new int[size];
    }

    void push(int num) {
        // Write your code here.
        if(isFull()==0) {
            TOP++;
            arr[TOP] = num;
        }
    }

    int pop() {
        // Write your code here.
        if(TOP!=-1) {
            int ans = arr[TOP];
            TOP--;
            return ans;
        }
        return -1;
    }
    
    int top() {
        // Write your code here.
        if(TOP!=-1) {
            int ans = arr[TOP];
            return ans;
        }
        return -1;
    }
    
    int isEmpty() {
        // Write your code here.
        if(TOP==-1) return 1;
        return 0;
    }
    
    int isFull() {
        // Write your code here.
        if(TOP+1==size) return 1;
        return 0;
    }
    
};