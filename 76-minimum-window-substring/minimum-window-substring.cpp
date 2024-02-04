class Solution {

public:

    string minWindow(string s, string t) {
        int n = s.size();
        unordered_map<char, int> mp;
        for(auto &i:t) mp[i]++;
        int count = mp.size();
        int i=0;
        int j=0;
        int start = 0;
        int mini = 1e9;
        while(j<n){
            mp[s[j]]--;
            if(mp[s[j]]==0){
                count--;
            }
            if(count==0){
                while(count==0){
                    if(mini>j-i+1){
                        mini = j-i+1;
                        start = i;
                    }
                    mp[s[i]]++;
                    if(mp[s[i]]>0){
                        count=1;
                    }
                    i++;
                }
            }
            j++;
        }

        if(mini != 1e9){
            return s.substr(start, mini);
        }
        return "";
    }

};