class Solution {
public:
    vector<int> arange(int a,int b,int c) {
        int k=0,l=0,m=0;
        if(a>b and a>c) return {a,max(b,c),min(b,c)};
        if(b>a and b>c) return {b,max(a,c),min(a,c)};
        return {c,max(a,b),min(a,b)};
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>> v;
        int n = nums.size();
        for(int i = 0 ; i < n ; i ++) {
            int j=i,k = n-1 ;
            while( j < k and j<n and k>=0){
                    int s = nums[i]+nums[j]+nums[k];
                    if( s==0 and (i!=j and i!=k and j!=k) ){
                        v.insert(arange(nums[i],nums[j],nums[k]));
                        j++;
                    }
                    else if(s>0) k--;   
                    else j++;
                }
            }
            vector<vector<int>> s(v.begin(),v.end());
        return s;
    }
};