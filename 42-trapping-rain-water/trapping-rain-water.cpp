class Solution {
public:
    int trap(vector<int>& height) {
        
        int n=height.size();
        if(n==0) return 0;

        int result=0;
        vector<int> v1(n),v2(n);

        v1[0]=height[0],v2[n-1]=height[n-1];

        for (int i=1;i<n;i++) v1[i]=max(v1[i-1],height[i]);
        for (int i=n-2; i>=0;i--) v2[i]=max(v2[i+1],height[i]);
        for (int i = 0; i < n; i++) result += min(v1[i], v2[i]) - height[i];
        
        return result;
    }
};