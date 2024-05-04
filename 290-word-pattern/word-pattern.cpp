class Solution {
public:
    bool wordPattern(string pattern, string s) {
        s+=" ";
        unordered_map<string,char> visit;
        unordered_map<char,int> used;
        int n=s.size(),j=0;
        string hash;
        for(int i=0;i<n;i++){
            if(s[i]!=' ') hash+=s[i];
            else{
                if(visit.count(hash)>0){
                    if(visit[hash]==pattern[j]) j++;
                    else return false;
                }
                else{
                    if(used.count(pattern[j])>0) return false;
                    visit[hash]=pattern[j];
                    used[pattern[j]]++;
                    j++;
                }
                hash="";
            }
        }
        if(j!=pattern.length()) return false;
        return true;
    }
};