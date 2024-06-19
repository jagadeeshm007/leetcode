class Solution {
public:
    int check(vector<int>& bloomDay, int m, int k, int day){
        int res = 0,cnt=0;
        for(int i=0;i<bloomDay.size();i++) {
            if(bloomDay[i]<=day && cnt<k){
                cnt++;
            }
            else{
                if(cnt==k) {
                    res++;
                }
                cnt=0;
            }
            if(cnt==k) {
                res++;
                cnt=0;
            }

        }

        if(res>=m) return true;
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(n< 1LL*m*k){
            return -1;
        }
        int mn=bloomDay[0],mx=bloomDay[0];
        for(auto it:bloomDay){
            mn = min(mn,it);
            mx = max(mx,it);
        }
        int low = mn,high=mx;

        while(low<high){
            int mid = low+(high-low)/2;

            if(check(bloomDay,m,k,mid)){
                high = mid;
            }
            else{
                low = mid+1;
            }
            // cout<<check(bloomDay,m,k,mid)<<" "<<high<<" "<<mid<<" "<<low<<endl;
            
        }
        return low;
    }
};