class Solution {
public:
    int gcd(int x, int y)
    {
        if(y==0)
            return 0;
        if(x%y==0)
            return y;
        else
            return gcd(y,x%y);
    }
    bool canMeasureWater(int x, int y, int z) {
        if(z>x+y)
            return false;
        else if(z==x+y || z==0)
            return true;
        int g = gcd(max(x,y),min(x,y));
        if(g==0)
            return false;
        if(z%g==0)
            return true;
        else
            return false;
    }
};
