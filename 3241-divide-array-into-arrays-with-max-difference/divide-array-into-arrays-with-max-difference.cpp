class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<vector<int> > r;
        vector<int> v;
        int n = nums.size() ;
        for(int i = 0 ; i < n ; i+=3 ) {
            for(int j = i ; j < i+3 ; j++){
                if(nums[j]-nums[i] <= k) v.push_back(nums[j]);
                else return {};
            }
            r.push_back(v);
            v.clear();
        }
        return r;
    }
};