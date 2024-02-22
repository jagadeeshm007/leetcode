class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> v(n,0);
        int j = -1,c=0;
        for(auto i : trust) v[i[0]-1] = 1;
        for(int i=0;i<n;i++) {
            if (v[i]==0) j=i+1;
        }

        if(j==-1) return -1;
        
        for(auto i : trust) {
            if(i[1]==j) c++;
        }

        if(c==n-1) return j;
        
        return -1;
    }
};