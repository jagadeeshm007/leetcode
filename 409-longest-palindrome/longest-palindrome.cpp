class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> frq;
        for(auto c : s) frq[c]++;
        
        int flg=0,ans=0;
        for(auto it : frq){
            if(it.second&1){
                if(flg==0)
                    {ans+=it.second;flg=1;}
                else
                    ans+=it.second-1;
            }
            else
                ans+=it.second;
        }
        return ans;

    }
};