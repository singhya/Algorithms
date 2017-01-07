class MovingAverage {
    queue<int> q;
    int sum;
    int n;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        n = size;
        sum = 0;
    }

    double next(int val) {
        if(q.size()==n)
        {
            sum = sum-q.front();
            q.pop();
        }
        sum+=val;
        q.push(val);
        return (double)sum/q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
