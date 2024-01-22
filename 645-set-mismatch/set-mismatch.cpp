class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size() ;
        int numsxor = 0, nxor = 0;
        for(int i = 1 ; i <= n ; i++ ) {
            numsxor^=nums[i-1] ;
            nxor^=i ;
        }

        int Xor = numsxor ^ nxor;
        int lsb = 0;
        while( !(Xor & (1 << lsb)) ) {
            lsb++;
        }

        int numszero = 0, numsone = 0;
        int nzero = 0, none = 0;
        for(int i = 0 ; i < n ; i++ ) { 
            if(nums[i] & 1<<lsb) {
                numsone ^= nums[i];
            }
            else {
                numszero ^= nums[i];
            }
        }
        for(int i = 1 ; i <= n ; i++ ) { 
            if(i & 1<<lsb) {
                none ^= i;
            }
            else {
                nzero ^= i;
            }
        }
        int v1 = numszero ^ nzero ;
        int v2 = numsone ^ none ;

        for(int i = 0 ; i < n ; i++ ) {
            if( nums[i] == v1 ) {
                return {v1,v2};
            }
        }

        return {v2,v1};
    }
};