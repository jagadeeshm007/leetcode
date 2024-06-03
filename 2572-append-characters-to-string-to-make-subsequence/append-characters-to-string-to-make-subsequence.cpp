class Solution {
public:
    int appendCharacters(string s, string t) {
        // AF
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        //
        int j = 0, n = t.length();
        for (auto c : s) {
            if (j < n && c == t[j])
                j++;
            if (j >= n)
                return 0;
        }
        return n - j;
    }
};