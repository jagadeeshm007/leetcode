class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> in(n+1,0);
        vector<int> out(n+1,0);
        for(auto i : trust) {
            in[i[1]]++;
            out[i[0]]++;
        }
        for(int i=1;i<=n;i++){
            if(out[i]<=0 and in[i]>=n-1) return i;
        }
        return -1;
    }
};