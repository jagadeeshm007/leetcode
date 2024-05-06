class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int frq[129];
        memset(frq,-1,sizeof(frq));
        int ans=0,mx=0, n= s.length(),prev=0;
        for(int i=0;i<n;i++){
            if(frq[s[i]] == -1){
                frq[s[i]] = i;
                ans++;
            }
            else{
                while(prev <= frq[s[i] ]){
                    frq[s[prev]] = -1;
                    prev++;
                    ans--;
                }
                frq[s[i] ] = i;
                ans++;
            }
            mx = max(mx,ans);
            //debugging print statement
            //cout<<s[i]<<" "<<frq[s[i]]<<" "<<ans<<" "<<mx<<" "<<prev<<endl;
        }
        return mx;
    }
};