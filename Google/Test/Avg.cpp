#include<iostream>
#include<string>
#include<cmath>
using namespace std;
class Solution{
public:
    int getNumber(int num){
        string str = to_string(num);
        int max = 0;
        for(int i=0;i<str.size()-1;i++){
            int first = str[i]-'0';
            int second = str[i+1]-'0';
            int avg = ceil((((float)first) + ((float)second))/2.0);
            int number = stoi(str.substr(0,i)+to_string(avg)+str.substr(i+2));
            max = std::max(number,max);
        }
        return max;
    }
};
int main(){
    Solution s;
    cout<<s.getNumber(432)<<endl;
    cout<<s.getNumber(10)<<endl;
    cout<<s.getNumber(66)<<endl;
    cout<<s.getNumber(235443)<<endl;
    cout<<s.getNumber(6436245)<<endl;
    cout<<s.getNumber(2353)<<endl;
    return 0;
}
