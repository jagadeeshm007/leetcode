class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        string ans="";
        int i;
        for(i=0;i<num.length();i++){
            while(!st.empty() && k>0 && st.top()>num[i]){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }

        while(!st.empty() && k>0){
            st.pop();
            k--;
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        for(int i=ans.length()-1;i>=0;i--){
            if(ans[i]=='0'){
                ans.pop_back();
            }
            else{
                break;
            }
        }
        reverse(ans.begin(),ans.end());

        return (ans=="")? "0":ans;
    }
};