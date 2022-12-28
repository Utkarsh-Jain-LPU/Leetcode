class MyQueue {
public:
    vector<int> vec;
    
    MyQueue() {
        vec.clear();
    }
    
    void push(int x) {
        vec.push_back(x);
    }
    
    int pop() {
        int val = vec[0];
        vec.erase(vec.begin());
        return val;
    }
    
    int peek() {
        return vec[0];
    }
    
    bool empty() {
        return vec.size() == 0;
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
