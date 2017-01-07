class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int upper_i = matrix.size();
        int upper_j;
        vector<int> res;
        if(upper_i>0)
            upper_j = matrix[0].size();
        else
           return res;
        int lower_i = 0;
        int lower_j = -1;
        bool isLoop = true;
        while(isLoop)
        {
            isLoop = false;
            cout<<endl<<"  "<<lower_i<<" "<<endl<<lower_j<<" "<<upper_j<<endl<<" "<<upper_i<<" "<<endl;
            for(int j=lower_j+1;j<upper_j && lower_i<upper_i;j++)
            {
                res.push_back(matrix[lower_i][j]);
                isLoop = true;
            }
            upper_j--;
            for(int i=lower_i+1;i<upper_i && lower_j<upper_j;i++)
            {

                res.push_back(matrix[i][upper_j]);
                isLoop = true;
            }
            upper_i--;
            for(int j=upper_j-1;j>lower_j && lower_i<upper_i;j--)
            {
                res.push_back(matrix[upper_i][j]);
                isLoop = true;
            }
            lower_j++;
            for(int i=upper_i-1;i>lower_i && lower_j<upper_j;i--)
            {
                res.push_back(matrix[i][lower_j]);
                isLoop = true;
            }
            lower_i++;
        }
        return res;
    }
};
