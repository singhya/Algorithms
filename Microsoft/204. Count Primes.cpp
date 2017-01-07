class Solution {
public:
    int countPrimes(int n) {
       int count = 0;
       if(n<=1)
           return 0;
       vector<int>opt(n,true);
       opt[0] = false;
       opt[1] = false;
       for(int i=2;i<=sqrt(n);i++)
       {
           if(opt[i]==false)
               continue;
           for(int j=2;i*j<n;j++)
               opt[i*j]=false;
       }
       for(int i=0;i<n;i++)
           if(opt[i])
               count++;
       return count;
    }
};
