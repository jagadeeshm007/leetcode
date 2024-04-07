class Solution {
public:
    bool checkValidString(string s) {
        int i=0,j=0;
        for (auto c:s) {
            i+=(c=='(')?1:-1;
            j+=(c!=')')?1:-1;
            if (j<0) 
                return false;
            i = max(i,0);
        }
        return i==0;
    }
};