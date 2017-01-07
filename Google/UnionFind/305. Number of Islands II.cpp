class Solution {
public:
    int findRoot( vector<int> &roots, int index)
    {
        if(roots[index]==index)
            return index;
        else
            return findRoot(roots,roots[index]);
    }
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<int> result;
        if(m==0)
            return result;
        vector<int>roots(m*n,-1);
        int count = 0;
        for(int k=0;k<positions.size();k++)
        {
            int i = positions[k].first;
            int j = positions[k].second;
            roots[i*n+j]=n*i+j;
            count++;
            if(i-1>=0 && roots[(i-1)*n+j]!=-1)
            {
                int root = findRoot(roots,(i-1)*n+j);
                if(root!=n*i+j)
                {
                    roots[root]=i*n+j;
                    count--;
                }
            }
            if(i+1<m && roots[(i+1)*n+j]!=-1)
            {
                int root = findRoot(roots,(i+1)*n+j);
                if(root!=n*i+j)
                {
                    roots[root]=n*i+j;
                    count--;
                }
            }
            if(j-1>=0 && roots[i*n+j-1]!=-1)
            {
                int root = findRoot(roots,i*n+j-1);
                if(root!=n*i+j)
                {
                    roots[root]=n*i+j;
                    count--;
                }
            }
            if(j+1<n && roots[i*n+j+1]!=-1)
            {
                int root = findRoot(roots,i*n+j+1);
                if(root!=n*i+j)
                {
                    roots[root] = n*i+j;
                    count--;
                }
            }
            result.push_back(count);
        }
        return result;
    }
};
