class Solution {
public:
    vector<int> dp;
    bool solve(int i,int n,vector<int>& arr,vector<int>& vis) {
        if(i>=n || i<0) return 0;
        if(arr[i] == 0) return 1;
        if(dp[i]!=-1) return dp[i];
        if(vis[i]) return 0;
        vis[i]=1;
        bool p=false,q=false;
       p = solve(i+arr[i],n,arr,vis);
        q = solve(i-arr[i],n,arr,vis);
        return dp[i] = (p|q);
    }
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int> vis(n,0);
        dp.resize(n+1,-1);
        return solve(start,n,arr,vis);
    }
};