class Solution {
public:
    int hIndex(vector<int>& citations) {
        int max = 0;
        int n = citations.size();
        if(n==0)
            return 0;
        vector<int> citation_count(n+1,0);
        for(int i=0;i<citations.size();i++)
        {
            if(citations[i]>=n)
                citation_count[n]++;
            else
                citation_count[citations[i]]++;
        }
        int t = 0;

        for(int i=n;i>=0;i--)
        {
            t+=citation_count[i];
            if(t>=i)
                max=std::max(i,max);
        }
        return max;
    }
};
