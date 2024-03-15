/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    vector<Interval> answer;
    if(newInterval.start > newInterval.end) {
        swap(newInterval.start, newInterval.end);
    }
    // flag to find if we are done with new interval addition
    int i=0, len = intervals.size(), flag =0;
    while(i < len) {
        Interval curr = Interval(intervals[i].start, intervals[i].end);
        // non-overlapping intervals before new interval
        if(!flag && curr.end < newInterval.start) {
            answer.push_back(curr);
            i++;
            continue;
        }
        // non-overlapping intervals after new interval
        else if(!flag && newInterval.end < curr.start) {
            answer.push_back(newInterval);
            // Inserted the new Interval
            flag =1;
            continue;
        }
        // we have taken care of the new Interval
        else if(flag) {
            answer.push_back(curr);
            i++;
        }
        // they are overlapping
        else if(!flag && max(curr.start , newInterval.start) <= min(curr.end , newInterval.end)) {
            curr.start = min(curr.start, newInterval.start);
            curr.end = max(curr.end, newInterval.end);
            int j = i+1;
            flag = 1;
            while(j < len) {
                // non-overlapping
                if(curr.end < intervals[j].start) {
                    answer.push_back(curr);
                    break;
                }
                // overlapping
                if(max(curr.start, intervals[j].start) <= min(curr.end , intervals[j].end)) {
                    curr.start = min(curr.start, intervals[j].start);
                    curr.end = max(curr.end, intervals[j].end);
                    j++;
                }
            }
            if(j == len) {
                answer.push_back(curr);
            }
            // Havent inserted J into the answer
            i = j;
        }
        
    }
    // never added newInterval
    if(!flag) {
        answer.push_back(newInterval);
    }
    return answer;
    
}
