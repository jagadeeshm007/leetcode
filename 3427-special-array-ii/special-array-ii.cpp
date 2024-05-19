class Solution {
public:
    vector<int> isSpecial(vector<int>& nums) {
        vector<int> v(nums.size(),1);
        for(int i=0;i<nums.size();i++ ) {
            if((i-1>=0)){
                if(i+1<nums.size()){
                    if((nums[i-1]&1)!=(nums[i+1]&1) || (nums[i-1]&1)==(nums[i]&1))
                        v[i]=0;
                }
                else{
                    if((nums[i-1]&1)==(nums[i]&1))
                        v[i]=0;
                }
            }
            if(i+1<nums.size()){
                if(i-1>=0){
                    if((nums[i-1]&1)!=(nums[i+1]&1) || (nums[i+1]&1)==(nums[i]&1))
                        v[i]=0;
                }
                else{
                    if((nums[i+1]&1)==(nums[i]&1))
                        v[i]=0;
                }
            }
        }
        return v;
    }
    vector<int> left(vector<int>& nums){
        vector<int> v(nums.size(),0);
        for(int i=1;i<nums.size();i++){
            if((nums[i-1]&1) != (nums[i]&1)){
                v[i]=1;
            }
        }
        return v;
    }
    vector<int> right(vector<int>& nums){
        vector<int> v(nums.size(),0);
        for(int i=0;i<nums.size()-1;i++){
            if((nums[i]&1) != (nums[i+1]&1)){
                v[i]=1;
            }
        }
        return v;
    }
    vector<int> presum(vector<int>& all){
        vector<int> v(all.size(),0);
        v[0]=all[0];
        for(int i=1;i<all.size();i++){
            v[i]+=v[i-1]+all[i];
        }
        return v;
    }
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> all = isSpecial(nums);
        vector<int> lef = left(nums);
        vector<int> rig = right(nums);
        vector<int> pre = presum(all);
        vector<bool> ans(queries.size(),false);
        for(int i=0;i<queries.size();i++){
            if(queries[i][1] == queries[i][0]){
                ans[i]=true;
            }
            int pas = (abs(queries[i][1] - queries[i][0])>1) ? pre[queries[i][1]-1]-pre[queries[i][0]]:0;
            int spa = queries[i][1]-queries[i][0]-1;
            if(spa == pas && (lef[queries[i][1]] && rig[queries[i][0]]) ){
                ans[i] = true;
            }
        }
        
        return ans;
        
    }
};