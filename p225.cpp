class MyStack {
public:
    vector<queue<int>> vq;
    int tag;
    /** Initialize your data structure here. */
    MyStack() {
        vq = vector<queue<int>>(2, queue<int>());
        tag = 0;
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        vq[tag].push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int ret = top();
        while (vq[tag].size() > 1) {
            vq[1-tag].push(vq[tag].front());
            vq[tag].pop();
        }
        vq[tag].pop();
        tag = 1 - tag;
        return ret;
    }
    
    /** Get the top element. */
    int top() {
        return vq[tag].back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return vq[tag].size() == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */
