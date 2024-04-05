class Solution {
public:
    string makeGood(string S) {
        stack<char> st;

        for(auto it:S) {
            if(!st.empty()){
                if((islower(it) && toupper(it) == st.top()) || (isupper(it) && tolower(it) == st.top())){
                    st.pop();
                    continue;
                }
            }
            st.push(it);
        }

        string ans ="";
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }

        return ans;
    }
};