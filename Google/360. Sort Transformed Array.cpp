class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        float min = (float)b*(-1)/(2*a);
        int i;
        vector<int> result;
        int n = nums.size();
        for(i=0;i<n;i++)
            if(nums[i]>min)
                break;
        int f=i;
        int back=i-1;
        while(f<n&&back>=0)
        {
            if(a*(a*(pow(nums[back],2))+b*nums[back]+c)<a*(a*(pow(nums[f],2))+b*nums[f]+c))
            {
                result.push_back(a*(pow(nums[back],2))+b*nums[back]+c);
                back--;
            }
            else
            {
                result.push_back(a*(pow(nums[f],2))+b*nums[f]+c);
                f++;
            }
        }
        while(f<n)
        {
            result.push_back(a*(pow(nums[f],2))+b*nums[f]+c);
            f++;
        }
        while(back>=0)
        {
            result.push_back(a*(pow(nums[back],2))+b*nums[back]+c);
            back--;
        }
        if(a<0)
            reverse(result.begin(),result.end());
        return result;
    }
};
