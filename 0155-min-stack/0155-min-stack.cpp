#include <stack>
#include <algorithm>

using namespace std;

class MinStack {
private:
    stack<int> st;    // Main stack to hold elements
    stack<int> minSt; // Auxiliary stack to track minimums

public:
    MinStack() {
        // Constructor
    }
    
    void push(int val) {
        st.push(val);
        
        // If minSt is empty, push val. 
        // Otherwise, push the minimum of val and current minimum.
        if (minSt.empty()) {
            minSt.push(val);
        } else {
            minSt.push(min(val, minSt.top()));
        }
    }
    
    void pop() {
        st.pop();
        minSt.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */