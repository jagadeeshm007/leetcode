class Solution {
public:
    void Fun(int ind,int n, string &digits,string &s,vector<string>&dp,map<char,string>&mp){
        if(ind==n){
            dp.push_back(s);
            return;
        }
            for(auto it:mp[digits[ind]]){
                s.push_back(it);
                Fun(ind+1,n,digits,s,dp,mp);
                s.pop_back();
            
        }
    }
    vector<string> letterCombinations(string digits) {

        if(digits.size()==0)return{};
        map<char,string>mp = {{'2',"abc"} ,{'3',"def"} ,{'4',"ghi"} , {'5',"jkl"} ,{'6',"mno"} ,{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"} };
        vector<string>dp;
        string s;
        Fun(0,digits.size(),digits,s,dp,mp);
        return dp;
    }
};