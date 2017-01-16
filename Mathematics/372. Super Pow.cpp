class Solution {
public:
    int power(int a, int b){
        int res = 1;
        for(int i=0;i<b;i++)
            res = (res * a%1337)%1337;
        return res;
    }
    int superPow(int a, vector<int>& b) {
       int n = b.size()-1, zeros = 0, res = 1;
       vector<int> values;
       a = a%1337;
       values.push_back(a);
       while(n>=0){
           res = (res * power(values[zeros], b[n--]))%1337;
           values.push_back(power(values[zeros++],10));
       }
       return res;
    }
};
