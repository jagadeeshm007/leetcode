class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(),k=2,j=1,c=1;
        if(n == 0) return 0;
        for(int i=1;i<n;i++){
            if(nums[i] == nums[i-1]){
                if(c<k) nums[j++]=nums[i];
                c++;
            }
            else{
                c=1;
                nums[j++] = nums[i];
            }
        }

        return j;
    }
};