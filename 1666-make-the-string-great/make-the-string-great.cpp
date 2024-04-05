class Solution {
public:
    string makeGood(string S) {
        string st ="";
        for(auto it:S) {
            if(!st.empty() && toupper(it) == toupper(st.back()) && it - st.back() !=0){
                st.pop_back();
                continue;
            }
            st.push_back(it);
        }
        return st;
    }
};