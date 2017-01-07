// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        long int start = 1;
        long int last = n;
        while(start<=last)// && counter--)
        {
            long int mid = (start+last)/2;
            //cout<<mid<<endl;
            if(guess(mid)==0)
                return mid;
            else if(guess(mid)==1)
                start = mid+1;
            else
                last = mid-1;
        }
        return -1;
    }
};
