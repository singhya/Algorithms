class Solution {
public:
    vector<int> findMax(vector<int> nums, int k)
    {
        int n = nums.size();
        vector<int> result;
        if(n==k)
            return nums;
        else if(k==0)
            return result;
        stack<int> s;
        int i =  0;
        while(i<n)
        {
            if(s.empty())
                s.push(nums[i]);
            else if(nums[i]>s.top())
            {
                while(!s.empty() && nums[i]>s.top() && k-s.size()<n-i)
                    s.pop();
                s.push(nums[i]);
            }
            else
                if(s.size()<k)
                    s.push(nums[i]);
            i++;
        }
        while(!s.empty())
        {
            result.insert(result.begin(),s.top());
            s.pop();
        }
        return result;
    }
    vector<int> merge(vector<int> nums1, vector<int> nums2){
        int i = 0, j=0;
        vector<int> res;
        while(i<nums1.size() && j<nums2.size())
            if(isBigger(vector<int>(nums1.begin()+i,nums1.end()),vector<int>(nums2.begin()+j,nums2.end())))
                res.push_back(nums1[i++]);
            else
                res.push_back(nums2[j++]);
        while(i<nums1.size()) res.push_back(nums1[i++]);
        while(j<nums2.size()) res.push_back(nums2[j++]);
        return res;
    }
    bool isBigger(vector<int> v1, vector<int> v2)
    {
        int i=0;
        while(i<v1.size() && i<v2.size())
        {
            if(v1[i]>v2[i])
                return true;
            else if(v1[i]<v2[i])
                return false;
            else
                i++;
        }
        if(i==v1.size())
            return false;
        else
            return true;
    }
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> res(k,-1);
        if(m<n)
            for(int i=max(k-n,0);i<=min(k,m);i++)
            {
                vector<int> new_res = merge(findMax(nums1,i),findMax(nums2,k-i));
                if(isBigger(new_res,res))
                    res = new_res;
            }
        else
            for(int i=max(k-m,0);i<=min(k,n);i++)
            {
                vector<int> new_res = merge(findMax(nums1,k-i),findMax(nums2,i));
                if(isBigger(new_res,res))
                    res = new_res;

            }
        return res;

    }
};
