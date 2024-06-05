class Solution {
public:
    vector<int> freq(string s){
        vector<int> fq(26,0);
        int n = s.length();
        for(int i=0;i<n;i++){
            fq[s[i] - 'a']++;
        }

        return fq;
    }
    vector<string> commonChars(vector<string>& words) {
        int n=words.size();
        vector<int> p = freq(words[0]);
        for(int i=1;i<n;i++){
            vector<int> q = freq(words[i]);
            for(int i=0;i<26;i++){
                p[i]=min(p[i],q[i]);
            }
        }

        vector<string> ans;
        for(int i=0;i<26;i++){
            while(p[i]){
                ans.push_back(string(1,'a'+i));
                p[i]--;
            }
        }

        return ans;
    }
};