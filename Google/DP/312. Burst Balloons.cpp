class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> new_nums(n+2);
        for(int i=0;i<n;i++)
        {
            new_nums[i+1] = nums[i];
        }
        new_nums[0] = new_nums[n+1] = 1;
        vector<vector<int>>opt(n+2,vector<int>(n+2,0));
        for(int k=1;k<=n;k++)
            for(int i=1;i<=n-k+1;i++)
                for(int j=i;j<=i+k-1;j++)
                    opt[i][i+k-1]=max(opt[i][i+k-1],new_nums[i-1]*new_nums[j]*new_nums[i+k]+opt[i][j-1]+opt[j+1][i+k-1]);
        return opt[1][n];
    }
};
