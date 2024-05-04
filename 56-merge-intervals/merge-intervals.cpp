#define pb push_back
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> Result;
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        for (int i = 0; i < n; i++) {
            if (Result.size() == 0 || Result.back()[1] < intervals[i][0])
                Result.pb(intervals[i]);
            else
                Result.back()[1] = max(Result.back()[1], intervals[i][1]);
        }

        return Result;
    }
};