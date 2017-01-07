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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int n = intervals.size();
        int i=0;
        while(i<n && intervals[i].start<=newInterval.start)
            i++;

        intervals.insert(intervals.begin()+i,newInterval);
        // eleminate clashing interval after insertion
        int f = i+1;
        while(f<n+1 && intervals[f].start<=newInterval.end)
            f++;
        intervals[i].end = max(newInterval.end,intervals[f-1].end);
        intervals[i].start = min(newInterval.start,intervals[f-1].start);
        intervals.erase(intervals.begin()+i+1,intervals.begin()+f);

        //  eleminate clashing intervals before insertion
        int b=i;
        while(b>=0 && intervals[b].end>=newInterval.start)
            b--;
        intervals[i].start = min(newInterval.start,intervals[b+1].start);
        intervals[i].end = max(intervals[i].end,intervals[b+1].end);
        intervals.erase(intervals.begin()+b+1,intervals.begin()+i);

        return intervals;
    }
};
