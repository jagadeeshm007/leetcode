class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0,j=0,s=0, ml=INT_MAX, n=nums.size();
        while(i<n){
            if(s < target)
                s+=nums[i++];
            else{
                ml = min( ml, i-j);
                s-=nums[j++];
            }
        }
        while(j<n){
            if(s>=target)
                ml = min( ml, i-j);
            s-=nums[j++]; 
        }
        return (ml==INT_MAX)?0:ml;
    }
};