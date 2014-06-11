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
struct mycomp{
    bool operator() (const Interval &a, const Interval &b) {return a.start<b.start;}
} comp;
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> r;
        if(intervals.empty()) return intervals;
        for(auto it=intervals.begin();it!=intervals.end();++it) {
            insertInterval(r, *it);
        }
        return r;
    }
private:
    void insertInterval(vector<Interval> &r, Interval e) {
        auto it=r.begin();
        while(it!=r.end()) {
            if(e.end<it->start) {
                r.insert(it, e);
                return;
            }else if(e.start>it->end) {
                it++;
            }else {
                e.start=min(e.start, it->start);
                e.end=max(e.end, it->end);
                it=r.erase(it);
            }
        }
        r.insert(it, e);
    }
};
