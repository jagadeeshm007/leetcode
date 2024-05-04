class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), ans =0;;
        vector<int> premin(n,0);
        vector<int> postmax(n,0);

        premin[0]=prices[0];
        postmax[n-1]=prices[n-1];

        for(int i=1,j=n-2;i<n;i++,j--){
            
            if(premin[i-1]>prices[i]) premin[i]=prices[i];
            else premin[i]=premin[i-1];

            if(postmax[j+1]<prices[j]) postmax[j]=prices[j];
            else postmax[j]=postmax[j+1];
        }
        for(int i=0;i<n;i++) ans=max(ans,postmax[i]-premin[i]);
        return ans;
    }
};