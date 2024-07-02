class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> vis(1001,0);
        vector<int> ans;
        for(int i=0;i<nums1.size();i++){
            vis[nums1[i]]++;
        }

        for(int i=0;i<nums2.size();i++){
            if(vis[nums2[i]]>=1){
                ans.push_back(nums2[i]);
                vis[nums2[i]]--;;
            }
        }

        return ans;
    }
};