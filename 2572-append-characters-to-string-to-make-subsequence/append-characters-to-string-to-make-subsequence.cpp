class Solution {
public:
    int appendCharacters(string s, string t) {
        //AF
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        //
        int j=0;
        for(int i=0;i<s.length();i++) {
            if(j<t.length() && s[i]==t[j]){
                j++;
            }
            if(j>=t.length()) return 0;
        }

        return t.length()-j;
    }
};