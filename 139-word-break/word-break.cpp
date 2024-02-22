class Solution {
public:
    int dp[301];
    int superman(string& s, map<string, int>& dic, int i) {
        if (i >= s.size())
            return 1;
        if (dp[i] != -1)
            return dp[i];
        string c = "";
        int k = 0;
        for (int j = i; j < s.size(); j++) {

            c += s[j];
            if (dic[c] == 1)
                k = superman(s, dic, j + 1);
            if (k == 1)
                return 1;
        }

        return dp[i] = k;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        memset(dp, -1, sizeof(dp));
        map<string, int> dic;
        for (auto i : wordDict)
            dic[i]++;
        return superman(s, dic, 0);
    }
};