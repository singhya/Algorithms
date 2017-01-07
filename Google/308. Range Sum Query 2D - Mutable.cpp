class NumMatrix {
private:
    vector<vector<int> > sums;
    vector<vector<int> > mat;
    int r;
    int c;
public:
    NumMatrix(vector<vector<int> > &matrix) {
        r = matrix.size()+1;
        if(matrix.size()==0)
            return;
        c = matrix[0].size()+1;
        sums = vector<vector<int> >(r, vector<int>(c,0));
        mat = matrix;
        for(int i=0;i<r;i++)
            sums[i][0]=0;
        for(int i=0;i<c;i++)
            sums[0][i]=0;
        for(int i=1;i<r;i++)
            for(int j=1;j<c;j++)
                sums[i][j]=sums[i-1][j]+sums[i][j-1]-sums[i-1][j-1]+matrix[i-1][j-1];
    }

    void update(int row, int col, int val) {
        int diff = val - mat[row][col];
        for(int i=row+1;i<r;i++)
            for(int j=col+1;j<c;j++)
                sums[i][j]+=diff;
        mat[row][col] = val;
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return sums[row2+1][col2+1]-sums[row2+1][col1]-sums[row1][col2+1]+sums[row1][col1];

    }
    void display()
    {
        for(int i=0;i<r;i++)
            {
                for(int j=0;j<c;j++)
                    cout<<sums[i][j]<<" ";
                cout<<endl;
            }
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.update(1, 1, 10);
// numMatrix.sumRegion(1, 2, 3, 4);
