/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        int maximum = 0;
        vector<Interval> result(0);
        if(intervals.size()==0)
            return result;
        for(int i=0;i<intervals.size();i++)
        {
            cout<<intervals[i].end<<endl;
            maximum = max(maximum,intervals[i].end);
        }
        cout<<maximum;
        vector<int> v(maximum+1,0);
        for(int i=0;i<intervals.size();i++)
            for(int j=intervals[i].start;j<intervals[i].end;j++)
                v[j] = 1;
        bool start = false;
        int start_index,end_index;
        for(int i=0;i<=maximum;i++)
        {
            if(v[i]&&!start)
            {
                start = true;
                start_index=i;
            }
            if(!v[i]&&start)
            {
                start = false;
                end_index = i-1;
                Interval i(start_index,end_index);
                result.push_back(i);
            }
        }
        if(start)
        {
            Interval i(start_index,maximum);
            result.push_back(i);
        }
        return result;
    }
};
