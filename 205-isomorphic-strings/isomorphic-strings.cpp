class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<int,int> mp,visit;
        for(int i = 0 ; i<s.length();i++){
            if( mp[s[i]] == 0) {
                if(visit[t[i]] == 0) {
                    mp[s[i]] = t[i] ;
                    visit[t[i]]++;
                }
                else return false;
            }
            else if( t[i] != mp[s[i]] ) return false;

        }
        return true;
    }
};