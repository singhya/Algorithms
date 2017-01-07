class Logger {
public:
    /** Initialize your data structure here. */
    map<string,int>m;
    Logger() {
    }

    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        if(m.find(message)==m.end())
        {
            m[message]=timestamp;
            return true;
        }
        else
        {
            if(timestamp>=10+m[message])
            {
                m[message] = timestamp;
                return true;
            }
            else
            {
                return false;
            }
        }
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger obj = new Logger();
 * bool param_1 = obj.shouldPrintMessage(timestamp,message);
 */
