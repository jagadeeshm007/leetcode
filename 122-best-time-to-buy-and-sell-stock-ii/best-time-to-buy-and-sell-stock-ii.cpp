class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(),ans=0;
        vector<int> st;
        st.push_back(prices[0]);
        for(int i=1;i<n;i++){
            if(st.back() < prices[i]){
                ans+=(prices[i] - st.back());
            }
            st.push_back(prices[i]);
        }
        return ans;
    }
};