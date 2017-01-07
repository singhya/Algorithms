struct oper
{
    vector<vector<int>> m;
    oper(vector<vector<int>> matrix)
    {
        m = matrix;
    }
    bool operator()(pair<int,int> a,pair<int,int>b)
    {
        return m[a.first][a.second]<m[b.first][b.second];
    }
};
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        multiset<pair<int,int>,oper> min_heap(matrix);
        for(int i=0;i<n;i++)
            min_heap.insert(pair<int,int>{0,i});
        k=k-1;
        while(k--)
        {
            pair<int,int> coord = *min_heap.begin();
            if(coord.first+1<n)
                min_heap.insert(pair<int,int>{coord.first+1,coord.second});
            min_heap.erase(min_heap.begin());
        }
        pair<int,int> coord = *min_heap.begin();
        return matrix[coord.first][coord.second];
    }
};
