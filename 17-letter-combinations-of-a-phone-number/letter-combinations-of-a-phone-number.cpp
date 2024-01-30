class Solution {
public:
    map<char,string>mp = {{'2',"abc"} ,{'3',"def"} ,{'4',"ghi"} , {'5',"jkl"} ,{'6',"mno"} ,{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"} };
    void Fun(int ind,int n, string &digits,string s,vector<string>&dp){
        if(ind==n){
            dp.push_back(s);
            return;
        }
            for(auto it:mp[digits[ind]]){
                Fun(ind+1,n,digits,s+it,dp);
        }
    }
    vector<string> letterCombinations(string digits) {

        if(digits.size()==0)return{};
        vector<string>dp;
        string s;
        Fun(0,digits.size(),digits,s,dp);
        return dp;
    }
};