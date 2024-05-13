class Solution {
public:
    int dp[501][501];
    int find(string& word1,string& word2,int i,int j) {
        if(i >= word1.size() || j >= word2.size())
            return max(word1.size()-i,word2.size()-j);
        
        if(dp[i][j] != -1)
            return dp[i][j];

        if(word1[i] == word2[j])
            return dp[i][j] = find(word1,word2,i+1,j+1);
        else{
            return dp[i][j] = 1 + min(find(word1,word2,i+1,j),
                                    min(find(word1,word2,i,j+1),
                                    find(word1,word2,i+1,j+1)));
        }
    }
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));
        return find(word1,word2,0,0);
    }
};