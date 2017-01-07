class Solution {
public:
    int calculate(string s) {
       stack<int>result;
       stack<int> op;
       int res = 0;
       int sign = 1;
       int num = 0;
       s="("+s+")";
       for(int i=0;i<s.length();i++)
       {
           if(s[i]==' ')
               continue;
           if(isdigit(s[i]))
           {
               num = num*10+(s[i]-'0');
           }
           else
           {
               res += num*sign;
               num = 0;
               if(s[i]=='+') sign = 1;
               else if(s[i]=='-') sign = -1;
               else if(s[i]=='(')
               {
                   result.push(res);
                   op.push(sign);
                   res = 0;
                   sign = 1;
               }
               else if(s[i]==')')
               {
                   res = res*op.top()+result.top();
                   op.pop();
                   result.pop();
               }
           }
       }
       return res;
    }
};
