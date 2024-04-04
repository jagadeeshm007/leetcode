class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int mx=0;
        for(auto it:s) {
            if(it=='(') st.push(it);
            if(it==')') {
                mx = max(mx,(int)(st.size()));
                st.pop();
            }
        }
        return mx;
    }
};