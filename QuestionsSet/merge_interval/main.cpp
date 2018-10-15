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
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {return (a.start < b.start);});
        vector<Interval> result;
        auto it = intervals.begin();
        while(it!=intervals.end()) {
            int i = 1;
            while ((*it).end >= (*(it + i)).start && ((it + i) != intervals.end())) {
                if ((*it).end < (*(it + i)).end) {
                    (*it).end = (*(it + i)).end;
                }
                ++i;
            }
            result.emplace_back(it->start, it->end);
            it = it + i;
        }
        return result;
    }
};
