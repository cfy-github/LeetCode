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
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        auto it=intervals.begin();
        auto it_pre=it;
        while(it!=intervals.end()) {
            if(newInterval.end<it->start) {
                if(it!=it_pre) {
                    it=intervals.erase(it_pre, it);
                    intervals.insert(it, newInterval);
                } else intervals.insert(it, newInterval);
                return intervals;
            }else if(newInterval.start>it->end) {
                it++;
                it_pre++;
            } else {
                newInterval.start=min(newInterval.start, it->start);
                newInterval.end=max(newInterval.end, it->end);
                it++;
            }
        }
        if(it!=it_pre) it=intervals.erase(it_pre, it);
        intervals.insert(intervals.end(), newInterval);
        return intervals;
    }
};
