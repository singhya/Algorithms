class Solution {
public:
    int romanToInt(string s) {
        map<string,int>m = {{"I",1},{"IV",4},{"V",5},{"IX",9},{"X",10}
                            ,{"XL",40},{"L",50},{"XC",90},{"C",100},
                            {"CD",400},{"D",500},{"CM",900},{"M",1000}};
        int j = 0;
        int result=0;
        for(int i=1;i<=s.size();i++)
            if(m.find(s.substr(j,i-j))==m.end()) {
                result+=m[s.substr(j,i-j-1)];
                j=i-1;
            }
        result+=m[s.substr(j)];
        return result;
    }
};
