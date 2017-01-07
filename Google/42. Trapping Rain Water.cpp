#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int a =0;
        int b=height.size()-1;
        int maximum=0;
        int leftmax=0;
        int rightmax=0;
        while(a<=b){
            leftmax=max(leftmax,height[a]);
            rightmax=max(rightmax,height[b]);
            if(leftmax<rightmax){
                maximum+=(leftmax-height[a]);       // leftmax is smaller than rightmax, so the (leftmax-A[a]) water can be stored
                a++;
            }
            else{
                maximum+=(rightmax-height[b]);
                b--;
            }
            cout<<"a: "<<a<<" b: "<<b<<" water: "<<maximum<<" leftmax:"<<leftmax<<" rightmax:"<<rightmax<<endl;
        }
    return maximum;
    }
};
int main()
{
    vector<int> v = {0,1,0,2,1,0,1,3,2,1,2,1};
    Solution s;
    cout<<s.trap(v);
    return 0;
}
