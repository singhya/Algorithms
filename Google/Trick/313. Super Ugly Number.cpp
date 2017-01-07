class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int len = primes.size();
        vector<int>ugly(n,0);
        vector<int>index(len,0);
        ugly[0]=1;
        for(int i=1;i<n;i++)
        {
            int min = INT_MAX;
            for(int j=0;j<len;j++)
            {
                min = std::min(primes[j]*ugly[index[j]],min);
            }
            ugly[i]=min;
            for(int j=0;j<len;j++)
            {
                if(ugly[i]==primes[j]*ugly[index[j]])
                    index[j]++;
            }
        }
        return ugly[n-1];
    }
};
