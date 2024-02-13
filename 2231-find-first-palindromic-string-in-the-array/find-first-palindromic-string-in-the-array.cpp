class Solution {
public:
    bool ispalindrom(string s) {
        int i=0;
        int j=s.length()-1;
            while(i<j){
                if(s[i]!=s[j]) return false;
                i++;
                j--;
            }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        for(auto s : words) if(ispalindrom(s)) return s;
        return "";
    }
};
static const int _ = []() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    return 0;
}();