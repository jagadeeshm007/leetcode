class Solution {
public:
    vector<int> dp;
    void gen(int low ,int high,int bot,int top) {
        string s = "123456789";
        for(int i = low ; i <= high ; i++ ) {

            for(int j = 0 ; j <(10-low);j++ ){
                string t =  s.substr(j,i); 
                int n = stoi(t);
                int lg = log10(n)+1;
                if( lg == i and n >=bot and n<= top ) {
                    dp.push_back(n);
                }
            }

        }
    }
    vector<int> sequentialDigits(int low, int high) {
        int ln = log10(low)+1;
        int hg = log10(high)+1;
        gen(ln,hg,low,high);
        return dp;
    }
};