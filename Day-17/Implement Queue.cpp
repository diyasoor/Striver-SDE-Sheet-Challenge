class Queue {
    int *arr;
    int cnt;
    int Front;
    int rear;
    int size;
public:
    Queue() {
        // Implement the Constructor
        size=100001;
        arr=new int[size];
        cnt=0, Front=0, rear=0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        return cnt==0;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        if(cnt!=size) {
            arr[rear%size] = data;
            rear++;
            cnt++;
        } 
    }

    int dequeue() {
        // Implement the dequeue() function
        if(isEmpty()) return -1;
        else {
            int ans = arr[Front%size];
            cnt--;
            Front++;
            return ans;
        }
    }

    int front() {
        // Implement the front() function
        if(isEmpty()) return -1;
        return arr[Front%size];
    }
};