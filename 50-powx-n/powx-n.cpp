class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0)
            return 1;
        double temp = myPow(x, n / 2);
        if (!(n&1))
            return temp * temp;
        else {
            return (n > 0) ?
                (x * temp * temp) : ((temp * temp) / x) ;
        }
    }
};
