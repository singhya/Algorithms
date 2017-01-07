/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool sortingFunction(Interval i, Interval j)
{
    return (i.start<j.start);
}
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> result(0);
        if(intervals.size()==0)
            return result;
        sort(intervals.begin(),intervals.end(),sortingFunction);
        Interval ptr = intervals[0];
        int to_compare = 1;
        while(to_compare<intervals.size())
        {
            if(ptr.end>=intervals[to_compare].start)
            {
                ptr.end = max(ptr.end,intervals[to_compare].end);
                to_compare++;
            }
            else
            {
                result.push_back(ptr);
                ptr = intervals[to_compare];
                to_compare++;
            }
        }
        result.push_back(ptr);
        return result;
    }
};
