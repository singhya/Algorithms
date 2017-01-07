class Solution {
public:
    string addStrings(string num1, string num2) {
        int n = num1.size();
        int m = num2.size();
        int carry = 0;
        int i = n-1;
        int j = m-1;
        string result = "";
        for(; i>=0 && j>=0; i--,j--){
            result=to_string(((num1[i]-'0'+num2[j]-'0')+carry)%10)+result;
            carry=((num1[i]-'0'+num2[j]-'0')+carry)/10;
        }
        while(i>=0){
            result=to_string(((num1[i]-'0')+carry)%10)+result;
            carry=((num1[i]-'0')+carry)/10;
            i--;
        }
        while(j>=0){
            result=to_string(((num2[j]-'0')+carry)%10)+result;
            carry=((num2[j]-'0')+carry)/10;
            j--;
        }
        if(carry==1){
            result="1"+result;
        }
        return result;
    }
};
