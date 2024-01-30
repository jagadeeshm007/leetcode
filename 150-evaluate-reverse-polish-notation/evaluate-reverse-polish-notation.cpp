class Solution {
public:
    int solve(int a ,int b , string op){
        if(op=="+") return a+b;
        if(op=="-") return b-a;
        if(op=="*") return a*b;
        int d = b/a;
        return (d);
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto i:tokens){
            if(i == "+" || i == "-" || i == "*" || i == "/"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                int r = solve(a,b,i);
                st.push(r);
            }
            else{
                st.push(stoi(i));
            }
        }
        return st.top();
    }
};