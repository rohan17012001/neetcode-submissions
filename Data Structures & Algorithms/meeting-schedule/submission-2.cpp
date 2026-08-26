/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    static bool sorting(const Interval& a, const Interval& b){
        return a.end<=b.start;
    }
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), sorting);
        int maxtillnow=-1;
        for(auto i: intervals){
            if(maxtillnow==-1) maxtillnow=i.end;
            else{
                if(i.start>=maxtillnow && i.end>i.start) maxtillnow=i.end;
                else return false;
            }
        }
        return true;
    }
};
