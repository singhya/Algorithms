class Solution {
public:
    int numWays(int n, int k) {
        int result=0;
        if(n==0)
            return 0;
        if(n==1)
            return k;
        int different = k*(k-1);
        int same = k;
        for(int i=3;i<=n;i++)
        {
            int temp = different;
            different = (different+same)*(k-1);
            same = temp;

        }
        return different+same;
    }
};
