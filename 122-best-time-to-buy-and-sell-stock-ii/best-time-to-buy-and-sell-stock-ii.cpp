class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(),ans=0;
        stack<int> st;
        st.push(prices[0]);
        for(int i=1;i<n;i++){
            if(st.top() < prices[i]){
                ans+=(prices[i] - st.top());
            }
            st.push(prices[i]);
        }
        return ans;
    }
};