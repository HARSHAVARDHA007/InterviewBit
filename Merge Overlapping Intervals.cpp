/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 bool comp(Interval a, Interval b) {
     if(a.start < b.start) return true;
     if(a.start == b.start && a.end < b.end)  return true;
     return false;
 }
vector<Interval> Solution::merge(vector<Interval> &arr) {
    sort(arr.begin(),arr.end(),comp);
    vector<Interval> ans;
    Interval curr = Interval(arr[0].start,arr[0].end);
    for(int i=1; i<arr.size(); i++) {
        // non overlapping
        if(curr.end < arr[i].start) {
            ans.push_back(curr);
            curr.start = arr[i].start;
            curr.end = arr[i].end;
        }
        // overlapping
        else if( max(curr.start , arr[i].start) <= min(curr.end, arr[i].end) ) {
            curr.start = min(curr.start,arr[i].start);
            curr.end = max(curr.end, arr[i].end);
        }
    }
    ans.push_back(curr);
    return ans;
}
