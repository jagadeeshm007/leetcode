class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0,j=0,local=0,cnt=0;

        while(i<n){
            if(!nums[i]) cnt++;
            if(cnt>k){
                local = max(local,i-j);
                while(j<i && nums[j]) j++;
                j++;
                if(cnt>0) cnt--;
                else j++;
            }
            i++;
        }
        local = max(local,i-j);
        return local;
    }
};