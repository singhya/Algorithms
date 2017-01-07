class Solution {
public:
    int traverse(vector<vector<int>> &skip, vector<bool> &visited, int walk, int &m, int &n, int last)
    {
        visited[last] = true;
        walk++;
        int result = 0;
        if(walk==n)
        {
            visited[last]=false;
            return 1;
        }
        else
            for(int i=1;i<=9;i++)
                if(!visited[i] && (skip[last][i]==0 || visited[skip[last][i]]))
                    result+=traverse(skip,visited,walk,m,n,i);
            if(walk>=m)
                result++;
        visited[last]=false;
        return result;

    }
    int numberOfPatterns(int m, int n) {
        vector<vector<int>>skip(10,vector<int>(10,0));
        skip[1][3] = skip[3][1] = 2;
        skip[3][9] = skip[9][3] = 6;
        skip[9][7] = skip[7][9] = 8;
        skip[1][7] = skip[7][1] = 4;
        skip[1][9] = skip[9][1] = 5;
        skip[2][8] = skip[8][2] = 5;
        skip[4][6] = skip[6][4] = 5;
        skip[7][3] = skip[3][7] = 5;
        int result = 0;
        vector<bool> visited(10,false);

        result+=4*traverse(skip,visited,0,m,n,1);
        result+=4*traverse(skip,visited,0,m,n,2);
        result+=traverse(skip,visited,0,m,n,5);
        return result;
    }
};
