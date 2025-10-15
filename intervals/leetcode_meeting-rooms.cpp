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
    bool canAttendMeetings(vector<Interval>& intervals) {
        // Sort intervals by start time
        sort(intervals.begin(), intervals.end(), [](Interval& a, Interval& b) {
            return a.start < b.start;
        });

        int prev = 0; // tracks the end time of the previous meeting
        for (Interval x : intervals) {
            // If current meeting starts before previous one ends, overlap exists
            if (x.start < prev) {
                return false;
            } else {
                // Update prev to current meeting's end time
                prev = x.end;
            }
        }
        return true; // No overlaps found
    }
};
