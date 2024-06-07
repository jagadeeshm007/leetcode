class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_map<string,int> mp;

        for(auto it:dictionary) mp[it]++;

        istringstream ss(sentence);
        string ans,word;

        while(ss >> word){
            int i=0;
            while(i < word.length()){
                string tmp = word.substr(0,i);
                if(mp.count(tmp)){
                    ans+=tmp+" ";
                    break;
                }
                i++;
            }
            if(i == word.length()) ans+=word+" ";
        } 
        return ans.substr(0,ans.length()-1);
    }
};