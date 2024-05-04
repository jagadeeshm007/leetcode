class Solution {
public:
    int romanToInt(string s) {
        int n = s.length();
        map<char,int> symbols;
        symbols['I'] = 1;symbols['V'] = 5;symbols['X'] = 10;symbols['L'] = 50;
        symbols['C'] = 100;symbols['D'] = 500;symbols['M'] = 1000;
        int ans = symbols[s[n-1]];
        for(int i=n-2;i>=0;i--){
            if(symbols[s[i+1]] <= symbols[s[i]] ) {
                ans+=symbols[s[i]];
            }
            else{
                ans-=symbols[s[i]];
            }
        }

        return ans;
    }
};