class MyQueue {
public:
    vector<stack<int>> vs;
    /** Initialize your data structure here. */
    MyQueue() {
        vs = vector<stack<int>>(2, stack<int>());
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        vs[0].push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int ret = peek();
        vs[1].pop();
        return ret;
    }
    
    /** Get the front element. */
    int peek() {
        if (vs[1].size() == 0) {
            while (vs[0].size()) {
                vs[1].push(vs[0].top());
                vs[0].pop();
            }
        }
        return vs[1].top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return vs[0].size() + vs[1].size() == 0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
