class Solution {
public:
    //Boyer-Moore Majority Vote Algorithm O(N) & O(1)
    int majorityElement(vector<int>& nums) {
        int c = 1;
        int n = nums[0];
        for(int i = 1 ; i < nums.size() ; i ++ ) {
            if( n == nums[i] ) c++;
            else c--;
            if(c == 0) {n = nums[i];c = 1;}
        }
        return n;
    }
};