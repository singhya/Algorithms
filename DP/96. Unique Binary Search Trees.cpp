class Solution {
public:
    int numTrees(int n) {
        vector<int> opt(n+1);
        opt[0] = 1;
        opt[1] = 1;
        for(int j=2;j<=n;j++)
        for(int i=0;i<=j-1;i++){
            opt[j] += (opt[i]*opt[j-i-1]);
        }
        return opt[n];
    }
};
