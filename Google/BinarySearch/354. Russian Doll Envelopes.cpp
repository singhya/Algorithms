struct oper
{
    bool operator()(pair<int,int>a, pair<int,int>b)
    {
        if(a.first==b.first)
            return a.second>b.second;
        else
            return a.first<b.first;
    }
};
class Solution {
public:
    int LIS(vector<pair<int,int>>envelopes)
    {
        int n = envelopes.size();
        vector<int>tails(n);
        int length = 0;
        for(int i=0;i<n;i++)
        {
            int start = 0;
            int last = length;
            int mid = (start+last)/2;
            while(start!=last)
            {
                if(envelopes[i].second>tails[mid])
                    start = mid+1;
                else
                    last = mid;
                mid = (start+last)/2;
            }
            tails[last]=envelopes[i].second;
            if(last==length)
            {
                length++;
            }
        }
        return length;
    }
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),oper());
        return LIS(envelopes);
    }
};
