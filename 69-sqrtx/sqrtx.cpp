class Solution {
public:
    int mod = 1000000007;
    int mySqrt(int x) {
        long long i=1,j=x;
        while(i<=j){
            long long m= ((i+j)%mod)/2;
            if(m * m == x) return (int)m%mod;
            if( m * m > x) j = m-1;
            else i=m+1;
        }
        return (int)(i-1)%mod;
    }
};