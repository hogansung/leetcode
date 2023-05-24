class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {}
    
    void push(int x) {
        if (st_s.size() == 0 or st_s.top() >= x) {
            st_s.push(x);
        }
        st_v.push(x);
    }
    
    void pop() {
        if (st_s.size() and st_s.top() == st_v.top()) {
            st_s.pop();
        }
        st_v.pop();
    }
    
    int top() {
        return st_v.top();
    }
    
    int getMin() {
        return st_s.top();
    }
    
    stack<int> st_s;
    stack<int> st_v;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
