#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool is_sqrt(int n)
    {
        return ((int)sqrt(n)*(int)sqrt(n)==n);
    }
    int numSquares(int n) {
        static vector<int> least_square{0};
        for(int i=least_square.size();i<=n;i++)
        {
            if(is_sqrt(i))
            {
                least_square.push_back(1);
                continue;
            }
            int minimum = i;
            for(int j=1;j<i;j++)
            {
                minimum = std::min(minimum,least_square[j]+least_square[i-j]);
            }
            least_square.push_back(minimum);
        }
        return least_square[n];
    }
};
int main()
{
    Solution s;
    cout<<s.numSquares(12)<<endl;
    cout<<s.numSquares(13)<<endl;
    return 0;
}
