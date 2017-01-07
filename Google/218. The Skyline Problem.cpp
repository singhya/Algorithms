class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        multimap<int,int> mm;
        for(int i=0;i<buildings.size();i++)
        {
            mm.emplace(buildings[i][0],buildings[i][2]);
            mm.emplace(buildings[i][1],-buildings[i][2]);
        }
        multiset<int> building = {0};
        vector<pair<int, int>> results;
        multimap<int, int>::iterator it = mm.begin();
        int prev_y = -1;
        int prev_x = -1;
        for(;it!=mm.end();it++)
        {
            if((*it).second>0)
            {
                building.insert((*it).second);
            }
            else
            {
                building.erase(building.find(-(*it).second));
            }
            if(next(it,1)!=mm.end())
            {
                if(*(building.rbegin())!=prev_y && (*next(it,1)).first!=(*it).first)
                {
                    results.push_back(make_pair((*it).first,*(building.rbegin())));
                    prev_x = (*it).first;
                    prev_y = *(building.rbegin());
                }
            }
            else if(*(building.rbegin())!=prev_y)
            {
                results.push_back(make_pair((*it).first,*(building.rbegin())));
                prev_x = (*it).first;
                prev_y = *(building.rbegin());
            }
        }
        return results;
    }
};
