class Solution {
public:
    bool isReflected(vector<pair<int, int>>& points)
    {
        int n=points.size();
        int min = INT_MAX;
        int max = INT_MIN;
        unordered_set<string>s;
        for(int i=0;i<n;i++)
        {
            min = std::min(min,points[i].first);
            max = std::max(max,points[i].first);
            s.insert(to_string(points[i].first)+"|"+to_string(points[i].second));
        }
        int sum = min+max;
        for(int i=0;i<n;i++)
            if(s.find(to_string(sum-points[i].first)+"|"+to_string(points[i].second))==s.end())
                return false;
        return true;
    }
};
