class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int n = s.length();
        int max = 0;
        map<char,int> count;
        int front = 0;
        int back = 0;
        int counter = 0;
        while(front<n)
        {
            if(count.find(s[front])!=count.end())
                count[s[front]]++;
            else
                count[s[front]]=1;
            while(count.size()>2)
            {
                if(count[s[back]]>1)
                {
                    count[s[back]]--;
                }
                else
                {
                    map<char,int>::iterator it = count.find(s[back]);
                    count.erase(it);
                }
                back++;
            }
            front++;
            max=std::max(max,front-back);
        }
        return max;
    }
};
