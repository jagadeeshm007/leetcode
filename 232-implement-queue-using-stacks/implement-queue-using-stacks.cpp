class MyQueue {
public:
    stack<int> st,rst;
    MyQueue() {
        
    }
    
    void push(int x) {
        if(st.empty()) st.push(x);
        else {
            while(!st.empty()){
                rst.push(st.top());
                st.pop();
            }
            st.push(x);
            while(!rst.empty()){
                st.push(rst.top());
                rst.pop();
            }
        }
    }
    
    int pop() {
        int k = st.top();
        st.pop();
        return k;
    }
    
    int peek() {
        return st.top();
    }
    
    bool empty() {
        return st.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */