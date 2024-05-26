class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        map<int,int> freq;
        for(auto it:nums2) freq[it  * k]++;
        long long result=0;
        
        for(auto j:nums1) {
            for(long long i=1;i*i<=j;i++) {
                if(j%i != 0) continue;
                result += freq[i];
                if(i != j/i) result += freq[j/i];
            }
        }
        return result;
    }
};