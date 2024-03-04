class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort( tokens.begin() , tokens.end() );

        int i=0,val = 0 ,n = tokens.size(),ans=0 , j = n ;

        while(i<n and i<j){
            ans=max(val,ans);
            if(val==0){
                if(tokens[i] <= power) {
                    val++;
                    power-=tokens[i];
                    i++;
                }
                else{
                    return max(val,ans);
                }
            }
            else{
                if(tokens[i] <= power) {
                    val++;
                    power-=tokens[i];
                    i++;
                }
                else{
                    val--;
                    power+=tokens[j-1];
                    j--;
                }
            }
        }

        return max(val,ans);
    }
};