class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long>sum(n+1,0);
        for(int i=0;i<n;i++)
            sum[i+1] = sum[i]+nums[i];
        return findCountWhileMerging(sum,0,n+1,lower,upper);
    }
    int findCountWhileMerging(vector<long>&sum ,int start, int end, int lower,int upper)
    {
        ///cout<<start<<" "<<end<<endl;
        if(end-start<=1) return 0;
        int mid = (start+end)/2;
        int count = findCountWhileMerging(sum,start,mid,lower,upper)
                  + findCountWhileMerging(sum,mid,end,lower,upper);
        int k=mid,j=mid,t=mid,r=0;
        vector<long>temp(end-start);
        for(int i=start;i<mid;i++)
        {
            while(k<end && sum[k]-sum[i]<lower) k++;
            while(j<end && sum[j]-sum[i]<=upper) j++;
            count += j-k;
            while(t<end && sum[t]<sum[i]) temp[r++] = sum[t++];
            temp[r++] = sum[i];
        }
        for(int i=0;i<t-start;i++)
            sum[start+i] = temp[i];
        return count;
    }
};
