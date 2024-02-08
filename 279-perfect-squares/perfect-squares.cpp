class Solution {
public:
    bool isperfect(int n) {
        int m = sqrt(n);
        if( n == m*m ) return 1;
        return 0;
    }
    bool threenumber(int n) {
        while(n%4==0) n/=4;
        if(n%8!=7) return true;
        else return false;
    }
    int numSquares(int n) {
        if(isperfect(n)) return 1 ;
        for(int i=1 ; i*i<=n ; i++ ) if(isperfect(n-(i*i))) return 2;
        if(threenumber(n)) return 3;
        return 4;
    }
};
//ishowspeed cheat code :| //
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();