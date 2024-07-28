class Solution {
public:
    unordered_map<string, bool> memo;

    bool unmatch(const string& s1, const string& s2) {
        if (s1.length() != s2.length()) return true;
        vector<int> cnt(26, 0);
        for (char c : s1) cnt[c - 'a']++;
        for (char c : s2) cnt[c - 'a']--;
        for (int c : cnt) {
            if (c != 0) return true;
        }
        return false;
    }

    bool isScramble(string s1, string s2) {
        if (s1 == s2) return true;
        if (unmatch(s1, s2)) return false;
        
        string key = s1 + "_" + s2;
        if (memo.find(key) != memo.end()) return memo[key];
        
        int n = s1.length();
        for (int i = 1; i < n; ++i) {
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i))) {
                memo[key] = true;
                return true;
            }
            if (isScramble(s1.substr(0, i), s2.substr(n-i)) && isScramble(s1.substr(i), s2.substr(0, n-i))) {
                memo[key] = true;
                return true;
            }
        }
        
        memo[key] = false;
        return false;
    }
};