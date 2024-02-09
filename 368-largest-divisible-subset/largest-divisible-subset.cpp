class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) 
    {   
        sort(nums.begin(),nums.end());
        
        int bb=0;
        int n=nums.size();

        int dp[n], prev[n];
        memset(dp, 1, sizeof(dp));
        memset(prev, -1, sizeof(prev));

        for(int i=0;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(nums[i]%nums[j]==0 && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    prev[i]=j;
                }
            }
            if(dp[i]>dp[bb]){
                bb=i;  
            }
        }
        vector<int> result;

        while(bb>=0){
            result.push_back(nums[bb]);
            bb=prev[bb];
        }

        return result;
    }
};