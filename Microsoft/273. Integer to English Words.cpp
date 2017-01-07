class Solution {
public:
    string utility(int num, map<int,string>m){
        string result = "";
        if(num/100>0)
            result = m[num/100]+" Hundred ";
        num = num%100;
        if(num>=20){
            result += m[(num/10)*10] + " ";
            if(num%10>0)
            result += m[num%10] + " ";
        }
        else if(num>0)
            result += m[num]+" ";
        return result;
    }
    string numberToWords(int num) {
            map<int,string> m = {{1,"One"},{2,"Two"},{3,"Three"},{4,"Four"},{5,"Five"},{6,"Six"},{7,"Seven"},{8,"Eight"},{9,"Nine"},{10,"Ten"},{11,"Eleven"},{12,"Twelve"},{13,"Thirteen"},{14,"Fourteen"},{15,"Fifteen"},{16,"Sixteen"},{17,"Seventeen"},{18,"Eighteen"},{19,"Nineteen"},{20,"Twenty"},{30,"Thirty"},{40,"Forty"},{50,"Fifty"},{60,"Sixty"},{70,"Seventy"},{80,"Eighty"},{90,"Ninety"}};
            string result = "";
            vector<int> traverser_value = {1000000000,1000000,1000,1};
            vector<string> traverser_string = {"Billion","Million","Thousand",""};
            if(num==0){
                return "Zero";
            }
            for(auto i=0;i<traverser_value.size();i++){
                if(num/traverser_value[i]>0){
                    result+=utility(num/traverser_value[i],m);
                    result+= traverser_string[i];
                    if(i!=traverser_value.size()-1)
                        result+=" ";
                    num = num%traverser_value[i];
                }
            }
            result.erase(result.end()-1);
            return result;
    }
};
