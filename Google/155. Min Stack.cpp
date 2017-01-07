class MinStack {
private:
    stack<int> data;
    stack<int> minimum;
public:
    /** initialize your data structure here. */
    MinStack() {
    }

    void push(int x) {
        if(data.empty())
        {
            data.push(x);
            minimum.push(x);
        }
        else
        {
            data.push(x);
            minimum.push(min(minimum.top(),x));
        }
    }

    void pop() {
        data.pop();
        minimum.pop();
    }

    int top() {
        return data.top();
    }

    int getMin() {
        return minimum.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
