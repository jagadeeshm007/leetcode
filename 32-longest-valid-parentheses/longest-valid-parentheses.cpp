class Solution {
public:
    int solve(string& s, int i, int openCount, int closeCount) {
        int p=0;
        if(openCount == closeCount) p = openCount+closeCount;
        if(i>=s.length()) return p;
        int pc = 0;
        if(s[i] =='(') pc = solve(s,i+1,openCount+1,closeCount);
        else if(openCount > closeCount) pc = solve(s,i+1,openCount,closeCount+1);
        return max(p,pc);
    }

    int longestValidParentheses(string s) {
        int mx = 0, n = s.size();
        for(int i=0;i<n;i++) mx = max(mx,solve(s,i,0,0));
        return mx;
    }
};
