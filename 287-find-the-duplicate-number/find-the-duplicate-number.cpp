class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        for(int i = 0 ; i < nums.size() ; i++ ){
            if(nums[abs(nums[i])-1]<0){
                return abs(nums[i]);
            }
            else{
                nums[abs(nums[i])-1] *= -1 ;
            }
        }
        return 0;
    }
};