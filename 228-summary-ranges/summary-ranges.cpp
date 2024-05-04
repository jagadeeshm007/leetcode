class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n= nums.size();
        vector<string> ans;
        string s="";
        int i=0,j=0;
        while(i<n){
            if(s.length()==0) s+=to_string(nums[i]);
            else if(nums[i]!=nums[i-1]+1){
                if(j!=i-1) s+="->"+to_string(nums[i-1]);
                ans.push_back(s);
                s="";
                j=i;
                continue;
            }
            i++;
        }
        if(j!=i-1 && i!=j) s+="->"+to_string(nums[i-1]);
        if(s.length()!=0) ans.push_back(s);
        return ans;
    }
};