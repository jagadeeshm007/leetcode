class Solution {
public:
   static bool comp(const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        vector<int> ans;
        sort(begin(envelopes),end(envelopes),comp);
        for(int i=0;i<envelopes.size();i++){
            int fnd = envelopes[i][1];
            int idx = lower_bound(begin(ans),end(ans),fnd) - ans.begin();
            if(idx >= ans.size()){
                ans.push_back(fnd);
            }
            else{
                ans[idx] = fnd;
            }
        }

        return ans.size();
    }
};