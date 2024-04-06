class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        int n = s.length();
        string ans = "";
        for(int i=0;i<n;i++) { 
            if(s[i] == '('){
                st.push(i);
            }
            if(s[i] == ')'){
                if(st.empty()){
                    st.push(i);
                }
                else if(s[st.top()] == '('){
                    st.pop();
                }
                else{
                    st.push(i);
                }
            }
        }
        while(!st.empty()){
            s[st.top()] = '*';
            st.pop();
        }
        for(int i=0;i<n;i++){
            if(s[i]!='*'){
                ans+=s[i];
            }
        }
        return ans;
    }
};