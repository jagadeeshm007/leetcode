class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1) return s;
        int n = s.length();
        string res="";
        for(int i=0;i<numRows;i++){
            int inc = (numRows-1) * 2;
            for(int j=i;j<n;j+=inc){
                res+=s[j];
                if(i>0 && i<(numRows-1) && j+inc - 2*i < n){
                    res+=s[j+inc - 2*i];
                }
            }
        }
        return res;
    }
};