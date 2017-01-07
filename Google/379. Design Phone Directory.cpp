class PhoneDirectory {
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    queue<int> available;
    queue<int> occupied;
    vector<bool>checker;
    PhoneDirectory(int maxNumbers) {
        for(int i=0;i<maxNumbers;i++)
           available.push(i);
        checker = vector<bool>(maxNumbers,true);
    }

    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if(available.empty())
            return -1;
        else
        {
            int to_return = available.front();
            available.pop();
            checker[to_return] = false;
            return to_return;
        }
    }

    /** Check if a number is available or not. */
    bool check(int number) {
        return checker[number];
    }

    /** Recycle or release a number. */
    void release(int number) {
        if(!checker[number])
        {
            available.push(number);
            checker[number] = true;
        }
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj.get();
 * bool param_2 = obj.check(number);
 * obj.release(number);
 */
