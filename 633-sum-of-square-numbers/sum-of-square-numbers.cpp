class Solution {
public:
    bool isperfect(long long n) {
        int m = sqrt(n);
        return m*m==n;
    }
    bool judgeSquareSum(int c) {
        if(!c) return true;
        for(long long i=0; i*i < c ; i++){
            if(isperfect(c - i*i)) return true;
        }
        return false;
    }
};
//fast AF :\ //
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();