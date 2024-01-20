static const int _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
class Solution {
public:
    int MOD = 1000000007;
    int sumSubarrayMins(vector<int>& arr) {
        stack<int> st;
        long long result = 0;
        for (int i = 0; i <= arr.size(); i++) {
            while (!st.empty()&&(i==arr.size()||arr[st.top()]>=arr[i])){
                int m = st.top();
                st.pop();
                int left = -1 , right = i;
                if(!st.empty()) left = st.top();
                long long c = (m - left) * (right - m) % MOD;
                result = ( result + (c * arr[m]) % MOD) % MOD;
            }
            st.push(i);
        }
        return (int)(result);
    }
};