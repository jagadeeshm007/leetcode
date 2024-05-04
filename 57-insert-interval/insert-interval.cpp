#define pb push_back
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,vector<int>& newInterval) {
        int size = intervals.size(), i = 0;
        vector<vector<int>> Result;
        while(i < size && intervals[i][1] < newInterval[0]) Result.pb(intervals[i++]);
        
        while(i < size && newInterval[1] >= intervals[i][0]){
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        Result.push_back(newInterval);
        while(i < size) Result.pb(intervals[i++]);
        return Result;
    }
};