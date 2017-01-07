class Solution {
public:
    int maxArea(vector<int> nums, int k)
    {
        int max = INT_MIN;
        int n = nums.size();
        int sum=0;
        int to_return=INT_MIN;
        multiset<int>sums;
        sums.insert(0);
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            auto u_bound = sums.upper_bound(sum-k);
            if(u_bound!=sums.end())
                to_return = std::max(to_return,sum-*u_bound);
            sums.insert(sum);
        }
        return to_return;
    }
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        if(m==0)
            return 0;
        int n = matrix[0].size();
        vector<int> col(m);
        int max = INT_MIN;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                col[j]=matrix[j][i];
            max = std::max(max,maxArea(col,k+1));
            for(int j=i+1;j<n;j++)
            {
                for(int l=0;l<m;l++)
                    col[l]+=matrix[l][j];
                max = std::max(max,maxArea(col,k+1));
            }
        }
        return max;
    }
};
