struct func
{
    vector<int> A;
    vector<int> B;
    func(vector<int> num1, vector<int> num2)
    {
        A=num1;
        B=num2;
    }
    bool operator()(pair<int,int> i, pair<int,int> j)
    {
        if((A[i.first]+B[i.second])!=(A[j.first]+B[j.second]))
            return (A[i.first]+B[i.second])<(A[j.first]+B[j.second]);
        else
            return A[i.first]>A[j.first];
    }
};
class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();
        vector<pair<int,int>> result;
        if(m==0 || n==0)
        {
            return result;
        }
        multiset<pair<int,int>,func>heap(func(nums1,nums2));
        for(int i=0;i<k &&i<m;i++)
        {
            heap.insert(pair<int,int>{i,0});
        }
        int total = m*n;
        while(k-- && total--)
        {
            pair<int,int>min = *heap.begin();
            result.push_back(pair<int,int>{nums1[min.first],nums2[min.second]});
            heap.erase(heap.begin());
            if(min.second+1<n)
            {
                heap.insert(pair<int,int>{min.first,min.second+1});
            }
        }
        return result;
    }
};
