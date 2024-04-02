class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int map[257] , visit[257];
        for(int i = 0 ; i<s.length();i++){
            if( map[s[i]] == 0) {
                if(visit[t[i]] == 0) {
                    map[s[i]] = t[i] ;
                    visit[t[i]]++;
                }
                else return false;
            }
            else if( t[i] != map[s[i]] ) return false;

        }
        return true;
    }
};