class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        double temp = myPow(x, n / 2);
        return (!(n&1)) ? temp * temp: (n > 0) ? (x * temp * temp) : ((temp * temp) / x) ;
    }
};
