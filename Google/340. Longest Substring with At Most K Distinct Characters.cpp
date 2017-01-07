class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int n = s.size();
        int max = 0;
        int left_ptr = 0;
        int right_ptr = 0;
        unordered_map<char,int> temp;
        while(right_ptr<n)
        {
            if(temp.find(s[right_ptr])==temp.end())
            {
                temp[s[right_ptr++]]=1;
            }
            else
            {
                temp[s[right_ptr++]]++;
            }
            while(temp.size()>k)
            {
                if(temp[s[left_ptr]]>1)
                {
                    temp[s[left_ptr++]]--;
                }
                else
                {
                    temp.erase(s[left_ptr++]);
                }
           }

            if(temp.size()<=k && max<right_ptr-left_ptr)
            {
                max = right_ptr-left_ptr;
            }
        }
        return max;
    }
};
