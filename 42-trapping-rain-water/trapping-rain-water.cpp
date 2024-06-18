class Solution {
public:
    int trap(vector<int>& height) {
        int fill=0, n = height.size();
        vector<int> left(n),right(n);
        left[0]=height[0];
        right[n-1]=height[n-1];
        for(int i=1;i<n;i++){
            left[i] = max(height[i],left[i-1]);
        }

        for(int j=n-2;j>=0;j--){
            right[j] = max(height[j],right[j+1]);
        }

        for(int i=0;i<n;i++){
            fill+=abs(height[i]-min(right[i],left[i]));
        }
        return fill;
    }
};