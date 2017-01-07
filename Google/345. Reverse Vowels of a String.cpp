class Solution {
public:
    string reverseVowels(string s) {
        int left_ptr = 0;
        int right_ptr = s.length()-1;
        string vowel = "aeiouAEIOU";
        while(left_ptr<right_ptr)
        {
            bool left_vowel_found = false;
            for(int i=0;i<vowel.length();i++)
            if(s[left_ptr]==vowel[i])
            {
                left_vowel_found = true;
            }
            if(!left_vowel_found)
            {
                left_ptr++;
            }
            bool right_vowel_found = false;
            for(int i=0;i<vowel.length();i++)
            if(s[right_ptr]==vowel[i])
            {
                right_vowel_found = true;
            }
            if(!right_vowel_found)
            {
                right_ptr--;
            }
            if(left_vowel_found && right_vowel_found)
            {
                char temp = s[left_ptr];
                s[left_ptr++] = s[right_ptr];
                s[right_ptr--] = temp;
            }
        }
        return s;
    }
};
