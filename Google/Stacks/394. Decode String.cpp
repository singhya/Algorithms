class Solution {
public:
    string decodeString(string s) {
        stack<int> digits;
        stack<string> str;
        s="1["+s+"]";
        for(int i=0;i<s.length();i++)
            if(s[i]>='0' && s[i]<='9')
                if(i-1>=0 && s[i-1]>='0' && s[i-1]<='9')
                {
                    int d = digits.top();
                    digits.pop();
                    d = d*10+s[i]-'0';
                    digits.push(d);
                }
                else
                    digits.push(s[i]-'0');
            else if(s[i]!=']')
                str.push(string(1,s[i]));
            else
            {
                string s="";
                while(str.top()!="[")
                {
                    s=str.top()+s;
                    str.pop();
                }
                str.pop();
                string string_to_be_inserted = "";
                for(int i=0;i<digits.top();i++)
                    string_to_be_inserted+=s;
                digits.pop();
                str.push(string_to_be_inserted);
            }
        return str.top();
    }
};
