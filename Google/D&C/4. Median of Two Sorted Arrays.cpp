class Solution {
public:
    double kth(vector<int>& num1, vector<int>& num2,int k)
    {
        int pointer = k/2;
        int length1 = num1.size();
        int length2 = num2.size();
        if(length1>length2)
        {
            return kth(num2,num1,k);
        }
        if(length1==0)
        {
            return num2[k-1];
        }
        if(k==1)
        {
            return min(num1[0],num2[0]);
        }
        int i = min(pointer,length1);
        if(num1[i-1]<num2[i-1])
        {
            vector<int> A(num1.begin()+i,num1.end());
            return kth(A, num2, k-i);
        }
        else
        {
            vector<int> A(num2.begin()+i,num2.end());
            return kth(A, num1, k-i);
        }

    }
    double findMedianSortedArrays(vector<int>& num1, vector<int>& num2) {
        int m = num1.size();
        int n = num2.size();
        int k = (num1.size()+num2.size())/2;
        if((m+n)%2!=0)
        {
            return kth(num1,num2,k+1);
        }
        else
            return (kth(num1,num2,k)+kth(num1,num2,k+1))/2;
    }
};
