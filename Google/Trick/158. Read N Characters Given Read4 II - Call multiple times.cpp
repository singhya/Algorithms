// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    char readBuffer[4];
    int copiedCounter;
    int readCount;
    Solution()
    {
        copiedCounter = 0;
        readCount = 0;
    }
    int read(char *buf, int n) {
        int ptr = 0;
        while(ptr<n)
        {
            if(copiedCounter==0)
                 readCount = read4(readBuffer);
            if(readCount==0)
                break;
            while(copiedCounter<readCount && ptr<n)
                buf[ptr++]=readBuffer[copiedCounter++];
            if(copiedCounter==readCount) copiedCounter = 0;
        }
        return ptr;

    }
};
