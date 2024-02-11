class Solution {
public:
    void sortColors(vector<int>& nums) {

        //  Dutch National Flag algorithm 
        int i = 0, m = 0, j = nums.size()-1;
        while(m<= j){
            if(nums[m] == 0){
                swap(nums[i], nums[m]);
                i++;
                m++;
            }
            else if(nums[m] == 1){
                m++;
            }
            else{
                swap(nums[m], nums[j]);
                j--;
            }
        }
    }
};