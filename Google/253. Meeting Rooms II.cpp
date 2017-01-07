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
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();
        vector<int> starting;
        vector<int> ending;
        for(auto i:intervals)
        {
            starting.push_back(i.start);
            ending.push_back(i.end);
        }
        sort(starting.begin(),starting.end());
        sort(ending.begin(),ending.end());
        int endptr = 0;
        int startptr = 0;
        int rooms = 0;
        int max = 0;
        while(startptr<n)
        {
            if(ending[endptr]>starting[startptr])
            {
                rooms++;
                max = std::max(max,rooms);
                startptr++;
            }
            else
            {
                rooms--;
                endptr++;
            }
        }
        return max;
    }
};
