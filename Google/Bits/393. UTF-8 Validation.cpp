class Solution {
public:
    int start(int i)
    {
        int count = 0;
        while(i&128 && count<8)
        {
            count++;
            i=i<<1;
        }
        return count;
    }
    bool validUtf8(vector<int>& data) {
        int n = data.size();
        int i=0;
        while(i<n)
        {
            int starting = data[i];
            int bytes = start(starting);
            if(bytes>=8 || bytes==1)
                return false;
            if(bytes==0)
            {
                i++;
                continue;
            }
            for(int j=i+1;j<i+bytes;j++)
                if(j>=n || (data[j]&192)!=128)
                    return false;
            i = i+bytes;
        }
        return true;
    }
};
