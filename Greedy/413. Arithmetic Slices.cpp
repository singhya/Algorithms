class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int p = 0, q = 2, sum = 0;
        while(q<A.size()){
            if(A[q]-A[q-1] != A[q-1]-A[q-2]){
                if(q-p>=3) sum+=((q-p-2)*(q-p-1))/2;
                p=q-1;
            }
            q++;
        }
        if(q-p>=3) sum+=((q-p-2)*(q-p-1))/2;
        return sum;
    }
};
